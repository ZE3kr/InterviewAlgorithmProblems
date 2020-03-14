package liner

import (
	"errors"
	"fmt"
	"math/big"
	"strconv"
	"strings"
)

type Mat struct {
	data []big.Rat
	row  int
	col  int
}

func NewMatRat(inputData []big.Rat, m int, n int) *Mat {
	if m < 0 || n < 0 || m*n != len(inputData) {
		panic("error size for the matrix")
	}
	data := make([]big.Rat, len(inputData))
	for i := 0; i < len(data); i++ {
		data[i].Set(&inputData[i])
	}
	return &Mat{data: data, row: m, col: n}
}

func NewMat(data []int64, m int, n int) *Mat {
	if m < 0 || n < 0 || m*n != len(data) {
		panic("error size for the matrix")
	}
	ratData := make([]big.Rat, len(data))
	for i := 0; i < len(data); i++ {
		ratData[i].SetInt64(data[i])
	}
	return &Mat{data: ratData, row: m, col: n}
}

func New1Mat(m int, n int) *Mat {
	ratData := make([]big.Rat, m*n)
	if m <= 0 || n <= 0 {
		panic("error size for the matrix")
	}
	for i := 0; i < m*n; i++ {
		ratData[i].SetInt64(1)
	}
	return &Mat{data: ratData, row: m, col: n}
}

func (inputMat *Mat) String() (s string) {
	format := "%"
	max := 0
	for _, k := range inputMat.data {
		l := len(k.String())
		if k.IsInt() {
			l -= 2
		}
		if l > max {

			max = l
		}
	}
	format += strconv.FormatInt(int64(max), 10)

	/* First line */
	s += "┌ "
	s += strings.Repeat(" ", inputMat.col*(max+1))
	s += "┐\n"

	/* For each element */
	for i := 0; i < inputMat.row; i++ {
		s += "│ "
		for j := 0; j < inputMat.col; j++ {
			if inputMat.data[i*inputMat.col+j].IsInt() {
				s += fmt.Sprintf(format+"d ", inputMat.data[i*inputMat.col+j].Num())
			} else {
				s += fmt.Sprintf(format+"s ", inputMat.data[i*inputMat.col+j].String())
			}
		}
		s += "│\n"
	}

	/* Last line */
	s += "└ "
	s += strings.Repeat(" ", inputMat.col*(max+1))
	s += "┘"
	return s
}

func (inputMat *Mat) Copy() *Mat {
	mat := NewMatRat(inputMat.data, inputMat.row, inputMat.col)
	return mat
}

func (inputMat *Mat) Set(mat *Mat) *Mat {
	data, m, n := mat.Data()
	inputMat.data = data
	inputMat.row = m
	inputMat.col = n
	return inputMat
}

func (inputMat *Mat) Data() ([]big.Rat, int, int) {
	newMat := inputMat.Copy()
	return newMat.data, newMat.row, newMat.col
}

func (x *Mat) Mul(a *Mat, b *Mat) *Mat {
	if a.row == 0 || a.col == 0 || b.row == 0 || b.col == 0 {
		panic("cannot multiply empty matrix")
	}
	if a.col != b.row {
		panic("error size for the matrix to multiply")
	}
	data := make([]big.Rat, a.row*b.col)

	for i := 0; i < a.row; i++ {
		for j := 0; j < b.col; j++ {
			for k := 0; k < a.col; k++ {
				data[i*a.col+j].Add(&data[i*a.col+j], new(big.Rat).Mul(&a.data[i*a.col+k], &b.data[k*b.col+j]))
			}
		}
	}

	copy(x.data, data)

	x.row = a.row
	x.col = b.col
	return x
}

func (x *Mat) Add(a *Mat, b *Mat) *Mat {
	if a.row == 0 || a.col == 0 || b.row == 0 || b.col == 0 {
		panic("cannot multiply empty matrix")
	}
	if a.row != b.row || a.col != b.col {
		panic("error size for the matrix to add")
	}
	x.data = make([]big.Rat, len(a.data))
	x.row = a.row
	x.col = b.col

	for i := 0; i < a.row; i++ {
		for j := 0; j < a.col; j++ {
			x.data[i*a.col+j].Add(&a.data[i*a.col+j], &b.data[i*a.col+j])
		}
	}
	return x
}

func (x *Mat) Neg(a *Mat) *Mat {
	x.Set(a)
	for i := 0; i < len(x.data); i++ {
		x.data[i].Neg(&x.data[i])
	}
	return x
}

func (x *Mat) swapRows(a int, b int) *Mat {
	for i := 0; i < x.col; i++ {
		var temp big.Rat
		temp.Set(&x.data[a*x.col+i])
		x.data[a*x.col+i].Set(&x.data[b*x.col+i])
		x.data[b*x.col+i].Set(&temp)
	}
	return x
}

func (c *Mat) Det(step bool) *big.Rat {
	a := new(Mat).Set(c)
	if step {
		fmt.Println("Input:")
		fmt.Println(a)
	}
	ans := big.NewRat(1, 1)
	if a.row <= 0 || a.col <= 0 {
		panic("cannot calculate determinate of an empty matrix")
	}
	if a.row != a.col {
		panic("not a square")
	}
	for i := 1; i < a.row; i++ {
		l := i - 1
		for ; l < a.row && a.data[l*a.col+i-1].Num().Int64() == 0; l++ {
		}
		if l == a.row {
			return new(big.Rat).SetInt64(0)
		} else if l != i-1 {
			ans.Neg(ans)
			a.swapRows(l, i-1)
			if step {
				fmt.Print("r", l+1, " <-> ", "r", i, "\n")
				fmt.Println(a)
			}
		}
		var inv big.Rat
		inv.Inv(&a.data[(i-1)*a.col+i-1])
		for k := i; k < a.row; k++ {
			numToMul := new(big.Rat).Set(&inv)
			numToMul.Mul(numToMul, &a.data[k*a.col+i-1])
			numToMul.Neg(numToMul)
			if step {
				fmt.Print("r", k+1, " + (", f(numToMul), ")r", i, "\n")
			}
			for j := 0; j < a.col; j++ {
				a.data[k*a.col+j].Add(&a.data[k*a.col+j],
					new(big.Rat).Mul(&a.data[(i-1)*a.col+j], numToMul))
			}
		}
		if step {
			fmt.Println(a)
		}
	}
	for i := 0; i < a.row; i++ {
		ans.Mul(ans, &a.data[i*a.row+i])
	}
	if step {
		fmt.Println("Result:")
		if ans.IsInt() {
			fmt.Println(ans.Num())
		} else {
			fmt.Println(ans)
		}
	}
	return ans
}

func (z *Mat) Scan(s fmt.ScanState, ch rune) error {
	m, n := 0, 0
	fmt.Scan(&m, &n)
	if m <= 0 || n <= 0 {
		return errors.New("error size for the matrix")
	}
	data := make([]big.Rat, m*n)
	for i := 0; i < len(data); i++ {
		fmt.Scan(&data[i])
	}

	z.data = data
	z.row = m
	z.col = n
	return nil
}

func (a *Mat) Row() int {
	return a.row
}

func (a *Mat) Col() int {
	return a.col
}

func Pow(a *Mat, n uint64) *Mat {
	var b Mat
	b.Set(a)
	switch n {
	case 0:
		return New1Mat(a.Row(), a.Col())
	case 1:
		return &b
	default:
		half := Pow(a, n/2)
		half.Mul(half, half)
		if n%2 == 1 {
			return half.Mul(half, a)
		} else {
			return half
		}
	}
}

func (a *Mat) Transpose(b *Mat) *Mat {
	data, m, n := b.Data()
	a.row = n
	a.col = m
	tData := make([]big.Rat, m*n)
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			tData[j*m+i].Set(&data[i*n+j])
		}
	}
	a.data = tData
	return a
}

func (a *Mat) Inv(b *Mat, step bool) *Mat {
	if b.row <= 0 || b.col <= 0 {
		panic("cannot calculate determinate of an empty matrix")
	}
	if b.row != b.col {
		panic("not mat square")
	}
	det := b.Det(false)
	if det.Num().Int64() == 0 {
		panic("the determinant is 0")
	}
	var mat Mat
	data := make([]big.Rat, b.col*b.row*2)
	mat.row = b.row
	mat.col = 2 * b.col
	mat.data = data
	for r := 0; r < b.row; r++ {
		for c := 0; c < b.col; c++ {
			data[r*mat.col+c].Set(&b.data[r*b.col+c])
		}
	}
	for r := 0; r < b.row; r++ {
		data[(1+r*2)*b.col+r].Set(new(big.Rat).SetInt64(1))
	}
	if step {
		fmt.Println("Let's assume the new Matrix B")
		fmt.Println(&mat)
	}

	for i := 1; i < mat.row; i++ {
		l := i - 1
		for ; l < mat.row && mat.data[l*mat.col+i-1].Num().Int64() == 0; l++ {
		}
		if l != i-1 {
			mat.swapRows(l, i-1)
			if step {
				fmt.Print("r", l+1, " <-> ", "r", i, "\n")
				fmt.Println(&mat)
			}
		}
		var inv big.Rat
		inv.Inv(&mat.data[(i-1)*mat.col+i-1])
		for k := i; k < mat.row; k++ {
			numToMul := new(big.Rat).Set(&inv)
			numToMul.Mul(numToMul, &mat.data[k*mat.col+i-1])
			numToMul.Neg(numToMul)
			if step {
				fmt.Print("r", k+1, " + (", f(numToMul), ")r", i, "\n")
			}
			for j := 0; j < mat.col; j++ {
				mat.data[k*mat.col+j].Add(&mat.data[k*mat.col+j],
					new(big.Rat).Mul(&mat.data[(i-1)*mat.col+j], numToMul))
			}
		}
		if step {
			fmt.Println(&mat)
		}
	}

	for i := mat.row - 2; i >= 0; i-- {
		var inv big.Rat
		inv.Inv(&mat.data[(i+1)*mat.col+i+1])
		for k := 0; k <= i; k++ {
			numToMul := new(big.Rat).Set(&inv)
			numToMul.Mul(numToMul, &mat.data[k*mat.col+i+1])
			numToMul.Neg(numToMul)
			if step {
				fmt.Print("r", k+1, " + (", f(numToMul), ")r", i+2, "\n")
			}
			for j := 0; j < mat.col; j++ {
				mat.data[k*mat.col+j].Add(&mat.data[k*mat.col+j],
					new(big.Rat).Mul(&mat.data[(i+1)*mat.col+j], numToMul))
			}
		}
		if step {
			fmt.Println(&mat)
		}
	}

	for i := 0; i < mat.row; i++ {
		if data[i*mat.col+i].Cmp(new(big.Rat).SetInt64(1)) != 0 {
			var inv big.Rat
			inv.Inv(&data[i*mat.col+i])
			if step {
				fmt.Print("r", i+1, " x (", f(&inv), ")\n")
			}
			for j := 0; j < mat.col; j++ {
				data[i*mat.col+j].Mul(&data[i*mat.col+j], &inv)
			}
		}
	}

	if step {
		fmt.Println(&mat)
	}

	a.col = b.col
	a.row = b.row
	aData := make([]big.Rat, b.col*b.row)
	a.data = aData
	for i := 0; i < b.row; i++ {
		for j := 0; j < b.col; j++ {
			aData[i*b.col+j] = data[(i*2+1)*b.col+j]
		}
	}
	return a
}

func (a *Mat) Inv2(b *Mat, c *Mat, step bool) *Mat { // returns b^-1 * c
	if b.row <= 0 || b.col <= 0 {
		panic("cannot calculate determinate of an empty matrix")
	}
	if b.row != b.col || b.row != c.row {
		panic("not mat square")
	}
	if b.Det(false).Num().Int64() == 0 {
		panic("the determinant is 0")
	}
	var mat Mat
	data := make([]big.Rat, (c.col+b.col)*b.row)
	mat.row = b.row
	mat.col = c.col + b.col
	mat.data = data
	for r := 0; r < b.row; r++ {
		for c := 0; c < b.col; c++ {
			data[r*mat.col+c].Set(&b.data[r*b.col+c])
		}
	}

	for r := 0; r < b.row; r++ {
		for col := 0; col < c.col; col++ {
			data[r*mat.col+b.col+col].Set(&c.data[r*c.col+col])
		}
	}

	if step {
		fmt.Println("Let's assume the new Matrix B")
		fmt.Println(&mat)
	}

	for i := 1; i < mat.row; i++ {
		l := i - 1
		for ; l < mat.row && mat.data[l*mat.col+i-1].Num().Int64() == 0; l++ {
		}
		if l != i-1 {
			mat.swapRows(l, i-1)
			if step {
				fmt.Print("r", l+1, " <-> ", "r", i, "\n")
				fmt.Println(mat)
			}
		}
		var inv big.Rat
		inv.Inv(&mat.data[(i-1)*mat.col+i-1])
		for k := i; k < mat.row; k++ {
			numToMul := new(big.Rat).Set(&inv)
			numToMul.Mul(numToMul, &mat.data[k*mat.col+i-1])
			numToMul.Neg(numToMul)
			if step {
				fmt.Print("r", k+1, " + (", f(numToMul), ")r", i, "\n")
			}
			for j := 0; j < mat.col; j++ {
				mat.data[k*mat.col+j].Add(&mat.data[k*mat.col+j],
					new(big.Rat).Mul(&mat.data[(i-1)*mat.col+j], numToMul))
			}
		}
		if step {
			fmt.Println(&mat)
		}
	}

	for i := mat.row - 2; i >= 0; i-- {
		var inv big.Rat
		inv.Inv(&mat.data[(i+1)*mat.col+i+1])
		for k := 0; k <= i; k++ {
			numToMul := new(big.Rat).Set(&inv)
			numToMul.Mul(numToMul, &mat.data[k*mat.col+i+1])
			numToMul.Neg(numToMul)
			if step {
				fmt.Print("r", k+1, " + (", f(numToMul), ")r", i, "\n")
			}
			for j := 0; j < mat.col; j++ {
				mat.data[k*mat.col+j].Add(&mat.data[k*mat.col+j],
					new(big.Rat).Mul(&mat.data[(i+1)*mat.col+j], numToMul))
			}
		}
		if step {
			fmt.Println(&mat)
		}
	}

	for i := 0; i < mat.row; i++ {
		if data[i*mat.col+i].Cmp(new(big.Rat).SetInt64(1)) != 0 {
			var inv big.Rat
			inv.Inv(&data[i*mat.col+i])
			if step {
				fmt.Print("r", i+1, " x (", f(&inv), ")\n")
			}
			for j := 0; j < mat.col; j++ {
				data[i*mat.col+j].Mul(&data[i*mat.col+j], &inv)
			}
		}
	}

	if step {
		fmt.Println(&mat)
	}

	a.col = c.col
	a.row = c.row
	aData := make([]big.Rat, c.col*c.row)
	a.data = aData
	for i := 0; i < c.row; i++ {
		for j := 0; j < c.col; j++ {
			aData[i*c.col+j] = data[i*mat.col+b.col+j]
		}
	}
	return a
}

func f(a *big.Rat) interface{} {
	if a.IsInt() {
		return a.Num()
	} else {
		return a
	}
}

func (a *Mat) StandardOutput() {
	fmt.Println(a.row, a.col)
	for i := 0; i < a.row; i++ {
		for j := 0; j < a.col; j++ {
			fmt.Print(f(&a.data[i*a.col+j]))
			if j < a.col-1 {
				fmt.Print(" ")
			} else {
				fmt.Print("\n")
			}
		}
	}
}
