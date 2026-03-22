char* convert(char* s, int numRows) {
    if (numRows == 1) return s;
    int len = strlen(s);
    char* res = (char*)malloc(len + 1);
    int index = 0;
    int cycle = 2 * numRows - 2;
    for (int i = 0; i < numRows; i++) {
        for (int j = i; j < len; j += cycle) {
            res[index++] = s[j];
            if (i != 0 && i != numRows - 1 && j + cycle - 2*i < len) {
                res[index++] = s[j + cycle - 2*i];
            }
        }
    }
    res[index] = '\0';
    return res;
}    
