/*** Sort and Random ***/

inline int random(int start, int end) {
	return (rand() % (end - start + 1)) + start;
}

int *partition(int A[], int p, int r) {
	int i = p - 1;
	int t = p - 1;
	int j, temp;
	int randomNum = random(p,r);
	temp = A[r];
	A[r] = A[randomNum];
	A[randomNum] = temp;
	int key = A[r];
	for (j = p; j < r; j++) {
		if (A[j] < key) {
			i++;
			t++;
			temp = A[t];
			A[t] = A[j];
			A[j] = temp;
			if (i < t) {
				temp = A[t];
				A[t] = A[i];
				A[i] = temp;
			}
		} else if (A[j] == key) {
			t++;
			temp = A[t];
			A[t] = A[j];
			A[j] = temp;
		}
	}
	temp = A[r];
	A[r] = A[t + 1];
	A[t + 1] = temp;
	int *po = (int *)malloc(sizeof(int) * 2);
	*po = i + 1;
	*(po + 1) = t + 1;
	return po;
}

void quickSort(int A[], int p, int r) {
	int *po;
	if (p < r) {
		po = partition(A, p, r);
		quickSort(A, p, *po - 1);
		quickSort(A, *(po + 1) + 1, r);
	}
}

void merge(int A[], int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	int *L = new int[n1];
	int *R = new int[n2];
	for (int i = 0; i < n1; i++) {
		L[i] = A[p + i];
	}

	for (int j = 0; j < n2; ++j) {
		R[j] = A[q + j + 1];
	}

	int i = 0, j = 0;
	for (int k = p; k < r + 1; ++k) {
		if (j >= n2) {
			A[k] = L[i];
			i++;
		} else if (i >= n1) {
			A[k] = R[j];
			j++;
		} else {
			if (L[i] < R[j]) {
				A[k] = L[i];
				i++;
			} else {
				A[k] = R[j];
				j++;
			}
		}
	}
	delete[] L;
	delete[] R;
}

void mergeSort(int A[], int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		mergeSort(A, p, q);
		mergeSort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

/*** Sort and Random End ***/
