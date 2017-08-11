public static int lcs(String str1, String str2) {
    int len1 = str1.length();
    int len2 = str2.length();
    int c[][] = new int[len1+1][len2+1];
    for (int i = 0; i <= len1; i++) {
        for( int j = 0; j <= len2; j++) {
            if(i == 0 || j == 0) {
                c[i][j] = 0;
            } else if (str1.charAt(i-1) == str2.charAt(j-1)) {
                c[i][j] = c[i-1][j-1] + 1;
            } else {
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }
    return c[len1][len2];
}
