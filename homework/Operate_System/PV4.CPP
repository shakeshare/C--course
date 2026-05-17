semaphore s12 = 0;
semaphore s13 = 0;
semaphore s24 = 0;
semaphore s25 = 0;
semaphore s46 = 0;
semaphore s56 = 0;

process P1()
{
	执行P1的工作;
	V(s12);
	V(s13);
}

process P2()
{
	P(s12);
	执行P2的工作;
	V(s24);
	V(s25);
}

process P3()
{
	P(s13);
	执行P3的工作;
	V(s24);
	V(s25);
}

process P4()
{
	P(s24);
	P(s24);
	执行P4的工作;
	V(s46);
	V(s56);
}

process P5()
{
	P(s25);
	P(s25);
	执行P5的工作;
	V(s46);
	V(s56);
}

process P6()
{
	P(s46);
	P(s56);
	执行P6的工作;
}
