int rowSums[3];
int colSums[3];
int matrix[3];
int numRows;
int numCols;

void initializeMatrix(void) {
	int i;
	i = 0;
	while (i < numRows * numCols) {
		matrix[i] = i;
		i = i + 1;
	}
}

void calculateRowSums(void) {
	int i;
	int j;
	i = 0;
	while (i < numRows) {
		rowSums[i] = 0;
		j = 0;
		while (j < numCols) {
			rowSums[i] = rowSums[i] + matrix[i * numCols + j];
			j = j + 1;
		}
		i = i + 1;
	}
}

void calculateColSums(void) {
	int i;
	int j;
	j = 0;
	while (j < numCols) {
		colSums[j] = 0;
		i = 0;
		while (i < numRows) {
			colSums[j] = colSums[j] + matrix[i * numCols + j];
			i = i + 1;
		}
		j = j + 1;
	}
}

void main(void) {
	int row;
	int col;

	numRows = 3;
	numCols = 3;
	initializeMatrix();
	calculateRowSums();
	calculateColSums();

	write "Enter row to sum: ";
	read row;
	if (row >= 0) {
		if (row < numRows) {
			write "Sum of row ";
			write row;
			write " is ";
			write rowSums[row];
			write "\n";
		}
		else {
			write "Invalid row index\n";
		}
	}
	else {
		write "Invalid row index\n";
	}

	write "Enter column to sum: ";
	read col;
	if (col >= 0) {
		if (col < numCols) {
			write "Sum of column ";
			write col;
			write " is ";
			write colSums[col];
			write "\n";
		}
		else {
			write "Invalid column index\n";
		}
	}
	else {
		write "Invalid column index\n";
	}
}
