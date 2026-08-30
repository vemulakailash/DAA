    int i = 0, j = 0, k = 0;
    // Merge while both arrays have elements
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
            result[k++] = a[i++];
