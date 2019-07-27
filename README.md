# lintcode
Solutions to Lintcode [US Giants Ladder](beestar.org)

Each cpp file in the subfolder under src contains solution to questions in lintcode. If you want to run a specific problem, uncomment the cpp file's respective lines like following:

		//*
		#pragma GCC diagnostic ignored "-Wunused-function"
		static//*/
		void test(){ // @suppress("Unused static function")
 
into 

		/*
		#pragma GCC diagnostic ignored "-Wunused-function"
		static//*/
		void test(){ // @suppress("Unused static function")
		
(by just removing the leading slash character) and build the project to run the test cases in the test function below those lines.
