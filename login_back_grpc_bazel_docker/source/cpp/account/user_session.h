
#include <string>

using namespace std;

namespace my_model{
	
	class UserSession{
	public:
		UserSession(int uid, string token, bool isOnline);

		int getUid();
		void setUid(int uid);

		string getToken();
		void setToken(string token);

		bool isOnline();
		void setOnline(bool isOnline);

	private:
		int uid;
		string token;
		bool mIsOnline;
	};

}