//
//  main.c
//  sqList
//
//  Created by AlienLi on 14-6-28.
//  Copyright (c) 2014年 AlienLi. All rights reserved.
//

#include <stdio.h>

#define Fail 0
#define Success 1
#define Status int


#define MAXSIZE 10
typedef char* ElemType;


typedef struct {
    ElemType value[MAXSIZE];
    int length;
}sqList;

Status createList(sqList *a)
{
    if (!a) {
        return Fail;
    }
    
    for (int i =0; i< MAXSIZE-4; i++) {
        a->value[i] = "liam";
        a->length = i;
        if (i == MAXSIZE -3) {
            a->value[i] = "wintan";
        }
    }
    return Success;
}

Status iteratorElement(sqList *a)
{
    if (!a) {
        return Fail;
        
    }
    else{
        for (int i = 0; i<MAXSIZE; i++) {
            printf("element: %s\n",a->value[i]);
        }
    
        return Success;
    }
    
    
}

Status getElementFromList(sqList list, int len, ElemType *n)
{
    if(len<0||len>list.length-1)
    {
        printf("list.length =%d",list.length);
        printf("beyong scope\n");
        return Fail;
    }else{
        *n = list.value[len];
        return Success;
    }
}

Status insertElementToList(sqList *list,int len, ElemType a)
{
    if (len<0||len>list->length) {
        return Fail;
    }else{
//        list.value[len] = *a;
//        list.value[len +1]
        list->length++;
        for (int j =len; j<list->length; j++) {
            printf("list.value[list.lenght]=%s\n",list->value[list->length]);

            list->value[list->length] = list->value[--list->length];
        }
        list->value[len] = a;
        
        return Success;
    }
}

Status deleteElemFromList(sqList *list,int len)
{
     printf("list->length:%d\n",list->length);
    if (len<0||
        len>=list->length
        ) {
        printf("超界");
        return Fail;
    }
    list->value[len] = NULL;
    for (int i = len; i<list->length; i++) {
        int j=i+1;

        list->value[i] = list->value[j];
        if (i ==list->length -1) {
            list->value[list->length] =NULL;
        }
    }
    list->length--;
    printf("list->length:%d\n",list->length);
    return Success;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    sqList list;
    createList(&list);
    
    if (createList(&list)) {
        printf("create list success");
    }
    
    iteratorElement(&list);
    
    ElemType m;
    if (getElementFromList(list, 4, &m)) {
         printf("m:%s\n",m);
    }
    printf("begin insert value\n");
    
    if (insertElementToList(&list, 5, "scofield")) {
        iteratorElement(&list);
    }
    
    if (deleteElemFromList(&list,3)) {
        printf("deleteElemFromList\n");
        iteratorElement(&list);
    }
    
    
    
    
   
    return 0;
    
    
}




