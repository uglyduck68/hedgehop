int  thread_settimer(int delay, void fn(void *), void *arg);
void thread_deletetimer(int timer_number);
void thread_timer_sleep(int t);
