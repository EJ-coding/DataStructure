SparseMatrix SparseMatrix::Multiply(SparseMatrix b)
{ // Return the product of the sparse matrices *this and b.
    if (cols != b.rows)
        throw "Incompatible matrices";
    SparseMatrix bXpose = b.FastTranspose();
    SparseMatrix d(rows, b.cols, 0);
    int currRowIndex = 0,
        currRowBegin = 0,
        currRowA = smArray[0].row;
    // set boundary conditions
    if (terms == capacity)
        ChangeSize1D(terms + 1);
    bXpose.ChangeSize1D(bXpose.terms + 1);
    smArray[terms].row = rows;
    bXpose.smArray[b.terms].row = b.cols;
    bXpose.smArray[b.terms].col = -1;
    int sum = 0;
    while (currRowIndex < terms)
    { // generate row currentRowA of d
        int currColB = bXpose.smArray[0].row;
        int currColIndex = 0;
        while (currColIndex <= b.terms)
        { // multiply row currRowA of *this by column currColB of b
            if (smArray[currRowIndex].row != currRowA)
            { // end of row currRowA
                d.StoreSum(sum, currRowA, currColB);
                sum = 0; // reset sum
                currRowIndex = currRowBegin;
                // advance to next column
                while (bXpose.smArray[currColIndex].row == currColB)
                    currColIndex++;
                currColB = bXpose.smArray[currColIndex].row;
            }
            else if (bXpose.smArray[currColIndex].row != currColB)
            { // end of column currColB of b
                d.StoreSum(sum, currRowA, currColB);
                sum = 0; // reset sum
                // set to multiply row currRowA with next column
                currRowIndex = currRowBegin;
                currColB = bXpose.smArray[currColIndex].row;
            }
            else if (smArray[currRowIndex].col <
                     bXpose.smArray[currColIndex].col)
                currRowIndex++; // advance to next term in row
            else if (smArray[currRowIndex].col ==
                     bXpose.smArray[currColIndex].col)
            { // add to sum
                sum += smArray[currRowIndex].value *
                       bXpose.smArray[currColIndex].value;
                currRowIndex++;
                currColIndex++;
            }
            else
                currColIndex++;                       // next term in currColB
        }                                             // end of while (currColIndex <= b.terms)
        while (smArray[currRowIndex].row == currRowA) // advance to next row
            currRowIndex++;
        currRowBegin = currRowIndex;
        currRowA = smArray[currRowIndex].row;
    } // end of while (currRowIndex < terms)
    return d;
}
