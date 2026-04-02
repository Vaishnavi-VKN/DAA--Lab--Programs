void boyerMoore(string txt, string pat) {
    int m = pat.size(), n = txt.size();
    int badChar[256];
    for (int i = 0; i < 256; i++) badChar[i] = -1;
    for (int i = 0; i < m; i++) badChar[(int)pat[i]] = i;

    int s = 0;
    while (s <= (n - m)) {
        int j = m - 1;
        while (j >= 0 && pat[j] == txt[s + j]) j--;
        if (j < 0) {
            cout << "Pattern found at: " << s << endl;
            s += (s + m < n) ? m - badChar[txt[s + m]] : 1;
        } else s += max(1, j - badChar[txt[s + j]]);
    }
}