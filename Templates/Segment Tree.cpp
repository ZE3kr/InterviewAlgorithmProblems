/*** Segment Tree ***/

int maxST[1000000 * 4], minST[1000000 * 4];
void buildSTMM(int l, int r, int id = 1) {
	int m;
	if (l == r) {
		scanf("%d", &maxST[id]);
		minST[id] = maxST[id];
		return;
	}
	m = (l + r) / 2;
	buildSTMM(l, m, id << 1);
	buildSTMM(m + 1, r, (id << 1) + 1);
	maxST[id] = max(maxST[id * 2], maxST[id * 2 + 1]);
	minST[id] = min(minST[id * 2], minST[id * 2 + 1]);
}

void buildSTMin(int l, int r, int id = 1) {
	int m;
	if (l == r) {
		scanf("%d", &maxST[id]);
		minST[id] = maxST[id];
		return;
	}
	m = (l + r) / 2;
	buildSTMin(l, m, id << 1);
	buildSTMin(m + 1, r, (id << 1) + 1);
	minST[id] = min(minST[id * 2], minST[id * 2 + 1]);
}

void buildSTMax(int l, int r, int id = 1) {
	int m;
	if (l == r) {
		scanf("%d", &maxST[id]);
		minST[id] = maxST[id];
		return;
	}
	m = (l + r) / 2;
	buildSTMax(l, m, id << 1);
	buildSTMax(m + 1, r, (id << 1) + 1);
	maxST[id] = max(maxST[id * 2], maxST[id * 2 + 1]);
}

int querySTmax(int l, int r, int L, int R, int id = 1) {
	int ret = -INF_INT;
	if (l <= L && r >= R)
		return maxST[id];
	int m = (L + R) / 2;
	if (l <= m)
		ret = max(ret, querySTmax(l, r, L, m, id << 1));
	if (r > m)
		ret = max(ret, querySTmax(l, r, m + 1, R, (id << 1) + 1));
	return ret;
}

int querySTmin(int l, int r, int L, int R, int id = 1) {
	int ret = INF_INT;
	if (l <= L && r >= R)
		return minST[id];
	int m = (L + R) / 2;
	if (l <= m)
		ret = min(ret, querySTmin(l, r, L, m, id << 1));
	if (r > m)
		ret = min(ret, querySTmin(l, r, m + 1, R, (id << 1) + 1));
	return ret;
}

void updateSTMM(int x, int y, int l, int r, int id = 1) {
	if (l == r) {
		maxST[id] = y;
		minST[id] = y;
		return;
	}
	int m = (l + r) / 2;
	if (x <= m)
		updateSTMM(x, y, l, m, id << 1);
	else
		updateSTMM(x, y, m + 1, r, (id << 1) + 1);
	maxST[id] = max(maxST[id * 2], maxST[id * 2 + 1]);
	minST[id] = min(minST[id * 2], minST[id * 2 + 1]);
}

void updateSTMin(int x, int y, int l, int r, int id = 1) {
	if (l == r) {
		maxST[id] = y;
		minST[id] = y;
		return;
	}
	int m = (l + r) / 2;
	if (x <= m)
		updateSTMin(x, y, l, m, id << 1);
	else
		updateSTMin(x, y, m + 1, r, (id << 1) + 1);
	maxST[id] = max(maxST[id * 2], maxST[id * 2 + 1]);
	minST[id] = min(minST[id * 2], minST[id * 2 + 1]);
}

void updateSTMax(int x, int y, int l, int r, int id = 1) {
	if (l == r) {
		maxST[id] = y;
		minST[id] = y;
		return;
	}
	int m = (l + r) / 2;
	if (x <= m)
		updateSTMax(x, y, l, m, id << 1);
	else
		updateSTMax(x, y, m + 1, r, (id << 1) + 1);
	maxST[id] = max(maxST[id * 2], maxST[id * 2 + 1]);
	minST[id] = min(minST[id * 2], minST[id * 2 + 1]);
}

/*** Segment Tree End ***/
