class	Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string secret;
    public:
        void    set_first_name(std::string name);
        std::string    get_first_name();
        void    set_last_name(std::string name);
        std::string    get_last_name();
        void    set_nick_name(std::string name);
        std::string    get_nick_name();
        void    set_phone_number(std::string name);
        std::string    get_phone_number();
        void    set_secret(std::string name);
        std::string    get_secret();
};