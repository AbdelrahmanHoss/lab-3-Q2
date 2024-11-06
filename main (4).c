#include <stdio.h>

void process_transactions(int transactions[], int length) {
    int balance = 1000;
    int tobeprocessed[length];
    int pending_trans = 0;
    
    for (int i=0;i<length;i++){
        if (transactions[i]<0 && transactions[i]+balance<0){
        printf("invalid transaction %d\n",transactions[i]);
        tobeprocessed[pending_trans++]=transactions[i];
        }else {
            balance +=transactions[i];
            if (balance == 0){
                printf("balance is zero. no futher transcations taken.\n");
                for (int j=i+1;j<length;j++){
                    tobeprocessed[pending_trans++] = transactions[j];
                    
                }
                break;
            
            } 
    
        }
    }
    printf("final balance is %d\n", balance);
    for (int i=0;i<pending_trans;i++){
    printf("unprocessed action %d\n", tobeprocessed[i]);
    }
}


int main(){
    int transactions[] = {-2000,-500,300,-800,100,-400,600};
    int length = sizeof(transactions)/sizeof(transactions[0]);
    process_transactions(transactions,length);
    return 0;
}
    
    
    
