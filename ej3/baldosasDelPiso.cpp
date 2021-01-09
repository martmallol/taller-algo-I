int baldosasDelPiso(int M, int N, int B) {
    int result = 0;
    int minBSobreM = 0;
    int minBSobreN = 0;
    if(M % B == 0) {
        minBSobreM = B;
    } else {
        minBSobreM = (M / B) + 1;
    }

    if(N % B == 0) {
        minBSobreN = B;
    } else {
        minBSobreN = (N / B) + 1;
    }
    result = minBSobreM * minBSobreN;
        return result;
	// Borrar el return dummy y completar
}
