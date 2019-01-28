void rotate(int** matrix, int matrixRowSize, int *matrixColSizes) {
    int n = matrixRowSize;
    int halfN = n>>1;
    int tmp;
    /* firstly transpose */
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }
    /* secondly, reflect by vertical middle axis */
    for(int i=0;i<halfN;i++){
        for(int j=0;j<n;j++){
            tmp = matrix[i][j];
            matrix[j][i] = matrix[j][n-i-1];
            matrix[j][n-i-1] = tmp;
        }
    }
}