typedef struct {
    int data;
    Node* next;
}Node;
Node node[6];
//0x14c->0xa8->0x39c->0x2b3->0x1dd->0x1bb
//0x6032d0: {0x14c, 0x6032e0}
//0x6032e0: {0xa8, 0x6032f0}
//0x6032f0: {0x39c, 0x603300}
//0x603300: {0x2b3, 0x603310}
//0x603310: {0x1dd, 0x603320}
//0x603320: {0x1bb, 0X0}

void phase_6(char* input){
    int a[6];
    read_six_numbers(input, a);
    
    for(int i = 0; i < 6; ++i)
        if(a[i] - 1 > 5) explode_bomb();
    
    for(int i = 0; i < 6; ++i)
        for(int j = i + 1; j < 6; ++j)
            if(a[i] == a[j]) explode_bomb();
        
    for(int i = 0; i < 6; ++i)
        a[i] = 7 - a[i];

    Node* pa[6];
    for(int i = 0; i < 6; ++i){
        Node* p = node;
        for(int j = 1; j < a[i]; ++j)
            p = p->next;
        pa[i] = p;
    }

    for(int i = 0; i < 5; ++i){
        pa[i]->next = pa[i + 1];
    }
    pa[5]->next = 0;

    for(int i = 0; i < 5; ++i)
        if(pa[i]->data < pa[i + 1]->data) 
            explode_bomb();
}   