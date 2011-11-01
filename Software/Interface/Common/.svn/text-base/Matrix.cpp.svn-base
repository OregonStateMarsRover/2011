/// VECTOR/MATRIX LIBRARY ///
/// by Ben Porter        ///
/// Questions?  Comments?  Firy catipillars?  Email me at xenovacivus@gmail.com
///                    ///
/// Version 1.1       ///


#include "Matrix.h"

///===vec2============= CONSTRUCTORS ====================///
vec2::vec2 (float x, float y){
    array[0] = x;
    array[1] = y;
}

vec2::vec2 (){
    array [0] = 0;
    array [1] = 0;
}


///===vec2============== DESTUCTOR ======================///
vec2::~vec2 ()
{
}


///===vec2============== OPERATORS ======================///

//RETURN NEGATIVE COPY-
vec2 vec2::operator- (){
    return vec2 (-array[0],
                 -array[1]);
}

//SUBTRACT-
vec2 vec2::operator- (vec2 A){
    return vec2 (array [0] - A.array [0],
                 array [1] - A.array [1]);
}

// ADD-
vec2 vec2::operator+ (vec2 A){
    return vec2 (array [0] + A.array [0],
                 array [1] + A.array [1]);
}

// SCALE (/FLOAT)-
vec2 vec2::operator/ (float A){
    if (A != 0)
        return vec2 (array [0]/A,
                     array [1]/A);
    else
        return vec2 (0, 0);
}

// SCALE (*FLOAT)-
vec2 vec2::operator* (float A){
    return vec2 (array[0]*A,
                 array[1]*A);
}

// DOT PRODUCT-
float vec2::operator*(vec2 A){
    return (float)(A.array[0]*array[0]+
                   A.array[1]*array[1]);
}

// GET AN ELEMENT-
float vec2::operator[] (int A){
    return array[A%2];
}

// GET POINTER TO ELEMENT-
float* vec2:: operator() (int A){
    return &array[A%2];
}

// SET TO ANOTHER ARRAY-
void vec2::operator= (float A [3])
{
    array [0] = A [0];
    array [1] = A [1];
}


///===vec3============= CONSTRUCTORS ====================///
vec3::vec3 (float x, float y, float z){
    array[0] = x;
    array[1] = y;
    array[2] = z;
}

vec3::vec3 (){
    array [0] = 0;
    array [1] = 0;
    array [2] = 0;
}


///===vec3============== DESTUCTOR ======================///
vec3::~vec3 ()
{
}


///===vec3============== OPERATORS ======================///

//RETURN NEGATIVE COPY-
vec3 vec3::operator- (){
    return vec3 (-array[0],
                 -array[1],
                 -array[2]);
}

//SUBTRACT-
vec3 vec3::operator- (vec3 A){
    return vec3 (array [0] - A.array [0],
                 array [1] - A.array [1],
                 array [2] - A.array [2]);
}

// ADD-
vec3 vec3::operator+ (vec3 A){
    return vec3 (array [0] + A.array [0],
                 array [1] + A.array [1],
                 array [2] + A.array [2]);
}

// SCALE (/FLOAT)-
vec3 vec3::operator/ (float A){
    if (A != 0)
        return vec3 (array [0]/A,
                     array [1]/A,
                     array [2]/A);
    else
        return vec3 (0, 0, 0);
}

// SCALE (*FLOAT)-
vec3 vec3::operator* (float A){
    return vec3 (array[0]*A,
                 array[1]*A,
                 array[2]*A);
}

// DOT PRODUCT-
float vec3::operator*(vec3 A){
    return (float)(A.array[0]*array[0]+
                   A.array[1]*array[1]+
                   A.array[2]*array[2]);
}

// GET AN ELEMENT-
float vec3::operator[] (int A){
    return array[A%3];
}

// GET POINTER TO ELEMENT-
float* vec3:: operator() (int A){
    return &array[A%3];
}

// SET TO ANOTHER ARRAY-
void vec3::operator= (float A [3])
{
    array [0] = A [0];
    array [1] = A [1];
    array [2] = A [2];
}

///XXXXXXXXXXXXXXXXXXXXX==================XXXXXXXXXXXXXXXXXXXXX///
///===================== VECTOR FUNCTIONS =====================///
///XXXXXXXXXXXXXXXXXXXXX==================XXXXXXXXXXXXXXXXXXXXX///




///===vecfunc============== LENGTH OF =========================///
float Length (vec2 A){
    return sqrt (A*A);
}
float Length (vec3 A){
    return sqrt (A*A);
}

///===vecfunc========== ANGLE BETWEEN A-0-B ===================///
float Angle (vec2 A, vec2 B){
    return acosd (A*B);
}
float Angle (vec3 A, vec3 B){
    return acosd (A*B);
}

///===vecfunc========== ANGLE BETWEEN A-B-C ===================///
float Angle (vec2 A, vec2 B, vec2 C){
    vec2 Vector1 = Normalize (A-B);
    vec2 Vector2 = Normalize (C-B);
    return acosd (Vector1*Vector2);
}
float Angle (vec3 A, vec3 B, vec3 C){
    vec3 Vector1 = Normalize (A-B);
    vec3 Vector2 = Normalize (C-B);
    return acosd (Vector1*Vector2);
}

///===vecfunc============== NORMALIZE =========================///
vec2 Normalize (vec2 A){
    return A/Length (A);
}
vec3 Normalize (vec3 A){
    return A/Length (A);
}

///===vecfunc============= CROSSPRODUCT =======================///
vec3 CrossProduct (vec3 A, vec3 B){
    return vec3 (A.array[1]*B.array[2] - A.array[2]*B.array[1],
                 A.array[2]*B.array[0] - A.array[0]*B.array[2],
                 A.array[0]*B.array[1] - A.array[1]*B.array[0]);
}


///===matrix======= ADD/SUBTRACT FROM POSITION ================///
matrix matrix::operator+(vec3 A){
    matrix temp = *this;
    temp.array [3][0]+= A[0];
    temp.array [3][1]+= A[1];
    temp.array [3][2]+= A[2];
    return temp;
}

matrix matrix::operator-(vec3 A){
    matrix temp = *this;
    temp.array [3][0]-= A[0];
    temp.array [3][1]-= A[1];
    temp.array [3][2]-= A[2];
    return temp;
}

///===matrix========== MULTIPLY MATRIX/VEC3 ===================///
/*matrix matrix::operator* (matrix A){
    matrix temp;

    for (int i=0; i<=3; i++)
    {
        for (int j=0; j<=2; j++)
        {
            temp.array [i][j] = vec3 (A.array [i][0], A.array [i][1], A.array [i][2])*
                                vec3 (  array [0][j],   array [1][j],   array [2][j]);
        }
    }

    temp.array [3][0]+= array [3][0];
    temp.array [3][1]+= array [3][1];
    temp.array [3][2]+= array [3][2];

    return temp;
}*/

matrix matrix::operator* (matrix A){
    matrix temp;
    for (int i=0; i<4; i++)
    {
        for (int k=0; k<4; k++)
        {
            temp.array[i][k] = 0;
            for (int j=0; j<4; j++)
            {
                temp.array[i][k] += this->array[i][j] * A.array[j][k];
            }
        }
    }
    //for (int i=0; i<=3; i++)
    //{
    //    for (int j=0; j<=2; j++)
    //    {
    //        temp.array [i][j] = vec3 (A.array [i][0], A.array [i][1], A.array [i][2])*
    //                            vec3 (  array [0][j],   array [1][j],   array [2][j]);
    //    }
    //}

    //temp.array [3][0]+= array [3][0];
    //temp.array [3][1]+= array [3][1];
    //temp.array [3][2]+= array [3][2];

    return temp;
}

vec3 matrix::operator* (vec3 A){
    vec3 temp;

    for (int i=0; i<3; i++)
    {
        //for (int k=0; k<4; k++)
        //{
        temp.array[i] = 0;

            temp.array[i] = 0;
            for (int j=0; j<4; j++)
            {
                if (j < 3)
                {
                    temp.array[i] += this->array[j][i] * A.array[j];
                }
                else
                {
                    temp.array[i] += this->array[j][i] * 1;
                }


                //temp.array[i][k] += this->array[i][j] * A.array[j][k];
            }
        //}
    }

    //temp.array [0] = vec3 (array [0][0], array [1][0], array [2][0]) * A;
    //temp.array [1] = vec3 (array [0][1], array [1][1], array [2][1]) * A;
    //temp.array [2] = vec3 (array [0][2], array [1][2], array [2][2]) * A;
    //temp = temp + vec3 (array [3][0], array [3][1], array [3][2]);
    return temp;
}

///===matrix============ ROTATION MATRICES ====================///
matrix MatrixRotateX (float theta){
    float s = sind (theta);
    float c = cosd (theta);
    return matrix (1, 0, 0, 0,
                   0, c, s, 0,
                   0,-s, c, 0,
                   0, 0, 0, 1);
}

matrix MatrixRotateY (float theta){
    float s = sind (theta);
    float c = cosd (theta);
    return matrix (c, 0,-s, 0,
                   0, 1, 0, 0,
                   s, 0, c, 0,
                   0, 0, 0, 1);
}

matrix MatrixRotateZ (float theta){
    float s = sind (theta);
    float c = cosd (theta);
    return matrix (c, s, 0, 0,
                  -s, c, 0, 0,
                   0, 0, 1, 0,
                   0, 0, 0, 1);
}

///===matrix=========== TRANSLATION MATRIX ====================///
matrix MatrixTranslate (float x, float y, float z){
    return matrix (1, 0, 0, 0,
                   0, 1, 0, 0,
                   0, 0, 1, 0,
                   x, y, z, 1);
}

///===matrix============= INVERT A MATRIX =====================///
matrix RTInvert (matrix A)
{
    matrix temp (A.array [0][0], A.array [1][0], A.array [2][0], 0,
                 A.array [0][1], A.array [1][1], A.array [2][1], 0,
                 A.array [0][2], A.array [1][2], A.array [2][2], 0,
                 0             , 0             , 0             , 1);

    temp.array[3][0] = -vec3 (A.array[0][0], A.array[0][1], A.array[0][2])*
                       vec3 (A.array[3][0], A.array[3][1], A.array[3][2]);
    temp.array[3][1] = -vec3 (A.array[1][0], A.array[1][1], A.array[1][2])*
                       vec3 (A.array[3][0], A.array[3][1], A.array[3][2]);
    temp.array[3][2] = -vec3 (A.array[2][0], A.array[2][1], A.array[2][2])*
                       vec3 (A.array[3][0], A.array[3][1], A.array[3][2]);
    return temp;
}

///===matrix=========== NORMALIZE A MATRIX ====================///
matrix Normalize (matrix A){
    vec3 X = Normalize (vec3 (A.array [0][0], A.array [0][1], A.array [0][2]));
    vec3 Y = Normalize (vec3 (A.array [1][0], A.array [1][1], A.array [1][2]));

    vec3 Z = CrossProduct (X, Y);
    Y = CrossProduct (Z, X);

    A.array [0][0] = X.array [0];
    A.array [0][1] = X.array [1];
    A.array [0][2] = X.array [2];

    A.array [1][0] = Y.array [0];
    A.array [1][1] = Y.array [1];
    A.array [1][2] = Y.array [2];

    A.array [2][0] = Z.array [0];
    A.array [2][1] = Z.array [1];
    A.array [2][2] = Z.array [2];

    return A;
}

///XXXXXXXXXXXXXXXXXXXXX===========================XXXXXXXXXXXXXXXXXXXXX///
///===================== END OF VEC/MATRIX CLASSES =====================///
///XXXXXXXXXXXXXXXXXXXXX===========================XXXXXXXXXXXXXXXXXXXXX///

