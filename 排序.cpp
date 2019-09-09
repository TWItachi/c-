#include <stdio.h>
#include <stdlib.h>
#define  MAX   8 /*���Ա����󳤶�*/

typedef int ElemType; /*����Ԫ������*/
/*˳������Ͷ���*/
typedef  struct
{
	 ElemType  data[MAX];
     int  length;  /*��ǰ��ĳ���*/
} SeqList;

/* ��ʼ�� */
SeqList *InitSeqlist()
{
    SeqList *L;
    L = (SeqList *)malloc(sizeof(SeqList));
    L->length = 0;

    return L;
}

/* ���� */
void input(SeqList *L)
{
    int i;


    for ( i=0; i<MAX; i++ )
    {
        L->data[i] = rand()%100;
        L->length++;
    }
}


/* ��� */
void output(SeqList *L)
{
    int i;

    for ( i=0; i<MAX; i++ )
        printf("%-4d", L->data[i]);

    printf("\n\n");
}



/* ð������  O(n^2) */
void BubbleSort( SeqList *L )
{
    int i, j, flag, tmp;

    for ( i=1; i<L->length; i++ )   /* ѭ��N-1�� */
    {
        flag = 0;   /* ��־λ */

        for ( j=0; j<L->length-i; j++ )
        {
            if ( L->data[j] > L->data[j+1] )
            {
                flag = 1;
                tmp = L->data[j];
                L->data[j] = L->data[j+1];
                L->data[j+1] = tmp;
            }
        }
        if ( flag == 0 )
            return ;
    }
}


/* ��������  O(nlog2^n) */
void QuickSort( SeqList *L, int s, int t )
{
    int i, j, tmp;

    i = s;
    j = t;
    if (s >= t)
    {
        return ;
    }
    tmp = L->data[s];
    while ( i < j )
    {
        /* �ҷ�������ɨ�� */
        while ( i<j && L->data[j] > tmp )    /* �ҷ���a[j] >= tmp ����������ɨ�� */
            j--;
        if ( i<j )        /* �ҷ���a[j] < tmp�� ��ֵ����ת������� */
        {
            // ����
            int t = L->data[j];
            L->data[j] = L->data[i];
            L->data[i] = t;
            i++;
        }
        /* ���������ɨ�� */
        while ( i<j && L->data[i] < tmp )
            i++;
        if ( i<j )
        {
            int t = L->data[j];
            L->data[j] = L->data[i];
            L->data[i] = t;
            j--;
        }
    }
    L->data[i] = tmp;
    /* �ݹ���� */
    QuickSort( L, s, i-1 );
    QuickSort( L, i+1, t );
}

/* ѡ������  O(n ^2) */
void selectSort( SeqList *L )
{
    int i, j, min, tmp;     /* �ô�ѭ����Сֵ�±�  */

    for ( i=0; i<L->length-1; i++ )
    {
        for ( j=i+1, min=i; j<L->length; j++ )
        {
            /* ����СֵΪa[min] �����¸�ֵmin */
            if ( L->data[j] < L->data[min] )
                min = j;
        }
        /* �ж� a[i] �Ƿ�����Сֵ�������������¸�ֵ */
        if ( min != i )
        {
            tmp = L->data[i];
            L->data[i] = L->data[min];
            L->data[min] = tmp;
        }
    }
}

/* �������� O(n^2) */
void InsertSort( SeqList *L )
{
    int i, j, tmp;

    /* i =1, ��һ��������Ϊ����ԣ�����������Ϊ����� */
    for ( i=1; i<L->length; i++ )
    {
        tmp = L->data[i];   /* tmp Ϊ�������� */
        j = i-1;    /* jָ��������ݵ�ǰһ������ */
        /* ѭ���ҳ��������ݵ�λ�ã�ͬʱ�������ݵĺ��� */
        while ( j>=0 && tmp < L->data[j] )
        {
            L->data[j+1] = L->data[j];
            j--;
        }
        L->data[j+1] = tmp;     /* j+1 Ϊ���������ݵ�λ�� */
    }
}

/* ϣ������  O(n^(2/3) */
void ShellSort( SeqList *L )
{
    int d, i, j, tmp;

    /* ÿ���� d Ϊ�����з��� */
    for ( d=L->length/2; d>0; d/=2 )
    {
        /* ÿ�ν���ÿ���һ�����ݵ����򣨷�ʱ�� */
        for ( i=d; i<L->length; i++ )
        {
            tmp = L->data[i];
            /* ֱ�����򣬴Ӻ���ǰ */
            for ( j=i-d; j>=0 && tmp<L->data[j]; j-=d )
            {
                L->data[j+d] = L->data[j];
            }
            L->data[j+d] = tmp;     /* ��Ϊ�ϲ�forѭ��������ִ����һ�� j-d */
        }
    }
}


/* �˵� */
int menu()
{
    int choice;

    printf("               |****************˳����������************|\n");
    printf("               |                 1. ð������            |\n");
    printf("               |                 2. ��������            |\n");
    printf("               |                 3. ѡ������            |\n");
    printf("               |                 4. ��������            |\n");
    printf("               |                 5. ϣ������              |\n");
    printf("               |                 0. �˳�                  |\n");
    printf("               |******************************************|\n");

    do{
        printf("������(0~5): ");
        scanf("%d", &choice);
    }while( choice < 0 || choice > 5 );

    return choice;
}


void form()
{
    SeqList *L;
    int flag=1;

    while ( flag )
    {
        switch( menu() )
        {
        case 1: /* 1. ð������ */
            printf("\t\tð������\n");
            L = InitSeqlist();
            input( L );
            printf("\n\tBefore sort: \n");
            output( L );
            BubbleSort( L );
            printf("\tSort:\n");
            output( L );
            printf("\n");
            system("pause"); //��ͣ
            system("cls"); //����
            break;
        case 2: /* 2. �������� */
            printf("\t\t��������\n");
            L = InitSeqlist();
            input( L );
            printf("\n\tBefore sort: \n");
            output( L );
            QuickSort( L, 0, MAX );
            printf("\tSort:\n");
            output( L );
            printf("\n");
            system("pause"); //��ͣ
            system("cls"); //����

            break;
        case 3: /* 3. ѡ������ */
            printf("\t\tѡ������\n");
            L = InitSeqlist();
            input( L );
            printf("\n\tBefore sort: \n");
            output( L );
            selectSort( L );
            printf("\tSort:\n");
            output( L );
            printf("\n");
            system("pause"); //��ͣ
            system("cls"); //����

            break;
        case 4: /* 4. �������� */
            printf("\t\t��������\n");
            L = InitSeqlist();
            input( L );
            printf("\n\tBefore sort: \n");
            output( L );
            InsertSort( L );
            printf("\tSort:\n");
            output( L );
            printf("\n");
            system("pause"); //��ͣ
            system("cls"); //����

            break;
        case 5: /* 5. ϣ������ */
            printf("\t\tϣ������\n");
            L = InitSeqlist();
            input( L );
            printf("\n\tBefore sort: \n");
            output( L );
            ShellSort( L );
            printf("\tSort:\n");
            output( L );
            printf("\n");
            system("pause"); //��ͣ
            system("cls"); //����

            break;
        case 0: /* 0. �˳� */
            flag = 0;
        }
    }
}



int main()
{
    form();

    return 0;
}
