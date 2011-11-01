/// VECTOR/MATRIX LIBRARY ///
/// by Ben Porter        ///
/// Questions?  Comments?  Firy catipillars?  Email me at xenovacivus@gmail.com
///                    ///
/// Version 1.1       ///


#ifndef matrixH
#define matrixH

#include <math.h>

/// Trig Functions In Degree- ///
#define PI_180 0.017453292519943295769
#define cosd(x) cos((x)*PI_180)
#define sind(x) sin((x)*PI_180)
#define tand(x) tan((x)*PI_180)
#define acosd(x) (acos((x))/PI_180)
#define asind(x) (asin((x))/PI_180)
#define atand(x) (atan((x))/PI_180)


///XXXXXXXXXXXXXXXXXXXXX============XXXXXXXXXXXXXXXXXXXXX///
///===================== VEC2 CLASS =====================///
///XXXXXXXXXXXXXXXXXXXXX============XXXXXXXXXXXXXXXXXXXXX///
class vec2
{
    public:

        float array [2];


        vec2 ();
        vec2 (float x, float y);
        ~vec2 ();

        vec2  operator-  ()     ;  // vec2 = -vec2
        vec2  operator-  (vec2) ;  // vec2 = vec2 - vec2
        vec2  operator+  (vec2) ;  // vec2 = vec2 + vec2
        vec2  operator/  (float);  // vec2 = vec2 / float
        vec2  operator*  (float);  // vec2 = vec2 * float
        float operator*  (vec2) ;  // float = vec2 * vec2

        float operator[] (int)  ;  // float = vec2[0]
        float*operator() (int)  ;  // *vec2 (0) = float || float = *vec2(0)
        void  operator=  (float[3]);// vec2 = float [2]

};

///XXXXXXXXXXXXXXXXXXXXX============XXXXXXXXXXXXXXXXXXXXX///
///===================== VEC3 CLASS =====================///
///XXXXXXXXXXXXXXXXXXXXX============XXXXXXXXXXXXXXXXXXXXX///
class vec3
{
    public:

        float array [3];


        vec3 ();
        vec3 (float x, float y, float z);
        ~vec3 ();

        vec3  operator-  ()     ;  // vec3 = -vec3
        vec3  operator-  (vec3) ;  // vec3 = vec3 - vec3
        vec3  operator+  (vec3) ;  // vec3 = vec3 + vec3
        vec3  operator/  (float);  // vec3 = vec3 / float
        vec3  operator*  (float);  // vec3 = vec3 * float
        float operator*  (vec3) ;  // float = vec3 * vec3

        float operator[] (int)  ;  // float = vec3[0]
        float*operator() (int)  ;  // *vec3 (0) = float || float = *vec3(0)
        void  operator=  (float[3]);// vec3 = float [3]



};

///===vecfunc====== VECTOR FUNCTION PROTOTYPES ================///
float Length (vec2);
float Length (vec3);

float Angle (vec2, vec2);
float Angle (vec3, vec3);

float Angle (vec2, vec2, vec2);
float Angle (vec3, vec3, vec3);

vec2 Normalize (vec2);
vec3 Normalize (vec3);

vec3 CrossProduct (vec3, vec3);


///XXXXXXXXXXXXXXXXXXXXX==================XXXXXXXXXXXXXXXXXXXXX///
///===================== MATRIX FUNCTIONS =====================///
///XXXXXXXXXXXXXXXXXXXXX==================XXXXXXXXXXXXXXXXXXXXX///
class matrix
{
    public:
    float array [4][4];

    vec3 Right ()
    {
        return vec3 (array [0][0], array [0][1], array [0][2]);
    }
    vec3 Left ()
    {
        return -Right ();
    }

    vec3 Up ()
    {
        return vec3 (array [1][0], array [1][1], array [1][2]);
    }
    vec3 Down ()
    {
        return -Up ();
    }

    vec3 Forward ()
    {
        return vec3 (array [2][0], array [2][1], array [2][2]);
    }
    vec3 Backward ()
    {
        return -Forward ();
    }

    matrix ()
    {
        for (int i = 0; i<=3; i++)
        {
            for (int j = 0; j<=3; j++)
            {
                if (i == j)
                    array [i][j] = 1.0f;
                else
                    array [i][j] = 0.0f;
            }
        }
    }

    matrix (float a, float b, float c, float d,
            float e, float f, float g, float h,
            float i, float j, float k, float l,
            float m, float n, float o, float p)
    {
        array [0][0] = a;
        array [0][1] = b;
        array [0][2] = c;
        array [0][3] = d;

        array [1][0] = e;
        array [1][1] = f;
        array [1][2] = g;
        array [1][3] = h;

        array [2][0] = i;
        array [2][1] = j;
        array [2][2] = k;
        array [2][3] = l;

        array [3][0] = m;
        array [3][1] = n;
        array [3][2] = o;
        array [3][3] = p;
    }

    matrix operator+(vec3 A);   // matrix = matrix + Vec3
    matrix operator-(vec3 A);   // matrix = matrix - Vec3
    //matrix operator+(float x);  // matrix = matrix + float
    //matrix operator-(float x);  // matrix = matrix - float
    matrix operator*(matrix A); // matrix = matrix * Matrix
    vec3   operator*(vec3 A);   // vec3   = matrix * Vec3
};

///===matrix============ ROTATION MATRICES ====================///
matrix MatrixRotateX (float theta);

matrix MatrixRotateY (float theta);

matrix MatrixRotateZ (float theta);

///===matrix=========== TRANSLATION MATRIX ====================///
matrix MatrixTranslate (float x, float y, float z);

///===matrix============= INVERT A MATRIX =====================///
matrix RTInvert (matrix A);
///===matrix=========== NORMALIZE A MATRIX ====================///
matrix Normalize (matrix A);

#endif

///XXXXXXXXXXXXXXXXXXXXX===========================XXXXXXXXXXXXXXXXXXXXX///
///===================== END OF VEC/MATRIX CLASSES =====================///
///XXXXXXXXXXXXXXXXXXXXX===========================XXXXXXXXXXXXXXXXXXXXX///

