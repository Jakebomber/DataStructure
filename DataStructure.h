#include <stdio.h>

enum STATUS
{
    GOOD = 0,
    ERROR = -1,
    FATAL = -2
};

enum BOOL
{
    TRUE = 1,
    FALSE = 0
};

enum TYPE
{
    Complex,
    Matrix,
    LinkNode,
    LinkList,
    HashTable,
    TreeNode,
    BiTree,
    Path,
    Vertex,
    Edge,
    Graph,
    Stack,
    Queue,
    BitArray,
    String,
    Set
};

typedef char *MESSAGE;

typedef struct RETURN_VAL
{
    STATUS s;
    MESSAGE msg;
} RETURN_VAL;

RETURN_VAL LAST_RET;

#define RETRES(ret)                       \
    LAST_RET = ret;                       \
    if (ret.s == STATUS.ERROR)            \
    {                                     \
        printf("ERROR:%s", LAST_RET.msg); \
    }                                     \
    else if (ret.s == STATUS.FATAL)       \
    {                                     \
        printf("FATAL:%s", LAST_RET.msg); \
        exit(-2);                         \
    }

typedef struct Complex
{
    TYPE t = TYPE::Complex;
    double real;
    double imag;
} Complex;

typedef struct Matrix
{
    TYPE t = TYPE::Matrix;
    char sparse = BOOL::FALSE; //TRUE:CSR FALSE:dense
    int LinNum = 0;
    int ColNum = 0;
    int *offset;
    int *colIdx;
    double *data = NULL;
} Matrix;

typedef struct LinkNode
{
    static const TYPE t = TYPE::LinkNode;
    struct LinkNode *before;
    struct LinkNode *next;
    void *data;
} LinkNode;

typedef struct LinkList
{
    static const TYPE t = TYPE::LinkList;
    int length = 0;
    LinkNode *head;
} LinkList;

typedef struct HashTable
{
    static const TYPE t = TYPE::HashTable;
    int length = 0;
    LinkList *data;
} HashTable;

typedef struct TreeNode
{
    static const TYPE t = TYPE::TreeNode;
    void *value;
    char LTag = -1;
    char RTag = -1;
    double weight = 0;
    struct TreeNode *Parent = NULL;
    struct TreeNode *LChild = NULL;
    struct TreeNode *RChild = NULL;
} TreeNode;

typedef struct BiTree
{
    static const TYPE t = TYPE::BiTree;
    int nodeNum = 0;
    TreeNode *root = NULL;
} BiTree;

typedef struct Path
{
    static const TYPE t = TYPE::Path;
    int length = 0;
    LinkList *data;
} Path;

typedef struct Edge Edge;

typedef struct Vertex
{
    static const TYPE t = TYPE::Vertex;
    int ID;
    double weight = 0;
    Edge **incidenceE;
} Vertex;

typedef struct Edge
{
    static const TYPE t = TYPE::Edge;
    int ID;
    double weight = 0;
    Vertex *incidenceV[2] = {NULL};
} Edge;

typedef struct Graph
{
    static const TYPE t = TYPE::Graph;
    Vertex *verts = NULL;
    Edge *edges = NULL;
} Graph;

typedef struct Stack
{
    static const TYPE t = TYPE::Stack;
    int length = 0;
    void *data;
} Stack;

typedef struct Queue
{
    static const TYPE t = TYPE::Queue;
    int length = 0;
    int capacity = 0;
    int startIdx = -1;
    void *data;
} Queue;

typedef struct BitArray
{
    static const TYPE t = TYPE::BitArray;
    unsigned long long len;
    unsigned char *data;
} BitArray;

typedef struct String
{
    static const TYPE t = TYPE::String;
    int length = 0;
    char *data;
} String;

typedef struct Set{
    static const TYPE t = TYPE::Set;
    int length;
    BiTree* data;
} Set;

//EOF