def mAdd(mat1,mat2):
    result = []
    for i in range(len(mat1)):
        row = []
        for j in range(len(mat1[0])):
            row.append(mat1[i][j]+mat2[i][j])
        result.append(row)
    return result

def mSub(mat1,mat2):
    result = []
    for i in range(len(mat1)):
        row = []
        for j in range(len(mat2[0])):
            row.append(mat1[i][j]-mat2[i][j])
        result.append(row)
    return result

def mMul(mat1,mat2):
    result = []
    for i in range(len(mat1)):
        row=[]
        for j in range(len(mat2[0])):
            element = 0
            for k in range(len(mat1[0])):
                element+=mat1[i][k]*mat2[k][j]
            row.append(element)
        result.append(row)
    return result

def mTrans(mat1):
    result=[]
    for i in range(len(mat1)):
        row = []
        for j in range(len(mat1[0])):
            row.append(mat1[j][i])
        result.append(row)
    return result


matrix1 = [[1,2],[3,4]]
matrix2 = [[5,6],[7,8]]

print("\nMatrix Addition : ",mAdd(matrix1,matrix2))
print("\nMatrix Subtraction : ",mSub(matrix1,matrix2))
print("\nMatrix Multiplication : ",mMul(matrix1,matrix2))
print("\nMatrix Transpose : ",mTrans(matrix1))
