#ifndef MatricDefine
    #include <stdio.h>
    #include <stdlib.h>

    #define MatricDefined

    typedef struct MatrixVerem {
        float vector[3];
        float matrix[3][3];
        float result[3];
    } MatrixVerem;
    
    void push_matrix();
    void pop_matrix();
#endif