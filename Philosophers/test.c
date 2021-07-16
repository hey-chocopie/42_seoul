#include <stdio.h>       
#include <pthread.h>   

#define NUM_THREADS 5
 
pthread_mutex_t mutexes[NUM_THREADS]; //mutex를 사용한다고 선언, pthread_mutex_t 자료형임.
pthread_cond_t conditionVars[NUM_THREADS]; // 데이터형은 pthread_cond_t 이다. 뮤텍스 정적 초기화
 
int permits[NUM_THREADS]; //포크 사용여
pthread_t tids[NUM_THREADS]; // 스레드 담을 그릇
 
void pickup_forks(int philosopher_number) {
    pthread_mutex_lock(&mutexes[philosopher_number%NUM_THREADS]);
    while (permits[philosopher_number%NUM_THREADS] == 0) {//젓가락 쓸수 있나 확인하고
        pthread_cond_wait(&conditionVars[philosopher_number%NUM_THREADS], &mutexes[philosopher_number%NUM_THREADS]);//못쓰면 wait를 걸어 mutexes락을 해제합니다.이 스레드는 잠시 뒤로 미뤄두고 conditionVars를 기다립니다.
    }
    permits[philosopher_number%NUM_THREADS] = 0;
    pthread_mutex_unlock(&mutexes[philosopher_number%NUM_THREADS]);
}
 
void return_forks(int philosopher_number) {
    pthread_mutex_lock(&mutexes[philosopher_number%NUM_THREADS]);
    permits[philosopher_number%NUM_THREADS] = 1;
    pthread_cond_signal(&conditionVars[philosopher_number%NUM_THREADS]);
    pthread_mutex_unlock(&mutexes[philosopher_number%NUM_THREADS]);
     
}
 
void* Philosopher(void * arg) {
    int philosopher_number;
    philosopher_number = (int)arg;
 
    // pickup left fork
    pickup_forks(philosopher_number);
    printf("philosopher(%d) picks up the fork(%d).\n", philosopher_number, philosopher_number);
     
    // pickup left fork
    pickup_forks(philosopher_number);
    printf("philosopher(%d) picks up the fork(%d).\n", philosopher_number, philosopher_number);
     
    // pickup right fork
    pickup_forks(philosopher_number+1);
    printf("philosopher(%d) picks up the fork(%d).\n", philosopher_number, (philosopher_number + 1) % NUM_THREADS);
     
    printf("philosopher(%d) starts eating \n", philosopher_number);
    sleep(2);
    printf("philosopher(%d) finishes eating \n", philosopher_number);
 
    // putdown right fork
    return_forks(philosopher_number + 1);
    printf("philosopher(%d) put down the fork(%d).\n", philosopher_number, (philosopher_number + 1) % NUM_THREADS);
 
    // putdown left fork
    return_forks(philosopher_number);
    printf("philosopher(%d) put down the fork(%d).\n", philosopher_number, philosopher_number);
 
    return NULL;
}
 void * OddPhilosopher(void * arg) {
    int philosopher_number;
    philosopher_number = (int)arg; //필로소퍼 번호
 
    // pickup right fork
    pickup_forks(philosopher_number + 1);
    printf("philosopher(%d) picks up the fork(%d).\n", philosopher_number, (philosopher_number + 1) % NUM_THREADS);
 
    // pickup left fork
    pickup_forks(philosopher_number);
    printf("philosopher(%d) picks up the fork(%d).\n", philosopher_number, philosopher_number);
 
    printf("philosopher(%d) starts eating \n", philosopher_number);
    sleep(2);
    printf("philosopher(%d) finishes eating \n", philosopher_number);
 
    // putdown left fork
    return_forks(philosopher_number);
    printf("philosopher(%d) puts down the fork(%d).\n", philosopher_number, philosopher_number);
 
    // putdown right fork
    return_forks(philosopher_number + 1);
    printf("philosopher(%d) puts down the fork(%d).\n", philosopher_number, (philosopher_number + 1) % NUM_THREADS);
 
    return NULL;
}
 
int main() {
    int i;
 
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_mutex_init(&mutexes[i], NULL); //이걸로 뮤텍스 초기화!! 기본으로 초기화 한다.
        pthread_cond_init(&conditionVars[i], NULL);// cond는 조건 변수인거같다. 조건 변수르 초기화한다는거 같은데, 조건변수??? 그게 뭐지??
        permits[i] = 1; // 포크 아무도 안쓰니까 일딴 1로 모두 사용가능하게 초기화
    } 

	// 모두 초기화 했다. 이제 스레드를 생성해 보자. 
    for (i = 0; i < NUM_THREADS; i++) {
        if (i % 2) {
            pthread_create(&tids[i], NULL, OddPhilosopher, (void*)(i));
			// 홀수 일때 // 그럼 로직 짤떄 이러면 되는거 아닌가? 
        }
        else{
            pthread_create(&tids[i], NULL, Philosopher, (void*)(i));
			//짝수 일
        }
    }
 
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(tids[i], NULL);
    }// 와 이렇게도 가능하구나 충격적이다. 스레드 모드다 끝나야 여기 탈출하겠지.
 
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_mutex_destroy(&mutexes[i]);
        pthread_cond_destroy(&conditionVars[i]);
    }// 사용한 뮤텍스랑 cond 조건변수를 제거해준다. 
 
    return 0;
} 
