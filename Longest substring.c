int lengthOfLongestSubstring(char* s) {
    int lastIndex[256];
    
    // Initialize all characters as not seen
    for (int i = 0; i < 256; i++) {
        lastIndex[i] = -1;
    }

    int maxLen = 0;
    int start = 0;  // start of current window

    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char c = s[i];

        // If character was seen and is inside current window
        if (lastIndex[c] >= start) {
            start = lastIndex[c] + 1;
        }

        lastIndex[c] = i;

        int currentLen = i - start + 1;
        if (currentLen > maxLen) {
            maxLen = currentLen;
        }
    }

    return maxLen;
}
