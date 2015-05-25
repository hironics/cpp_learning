class Singleton
{
	private:
		Singleton(){}; //the key is to hide constructor
		Singleton(const Singleton &s){};
		static Singleton* single ;
		static bool instanceFlag ;
		
		int i;

	public:
		static Singleton* getInstance();
		void testMethod();
		~Singleton()
		{
			delete single;
			instanceFlag = false;
		}
};  //declare a class, watch out ending ";"

