#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): Form("Shrubbery CreationForm", 145, 137), Target("my_tree")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const _Name) : Form("Shrubbery CreationForm", 145, 137), Target(_Name)
{
	;
}


ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &rhd) : Form(rhd)
{
	Target = rhd.Target;
}
//execute(Bureaucrat const & executor) const
void	ShrubberyCreationForm::execute(Bureaucrat const &rhd) const
{
	check_signed_and_grade(rhd);

	std::ofstream file;
	file.open(this->Target + "_shrubbery", std::ios::trunc); 
	if(file.is_open())
	{
		file << 
"		                    🌞                          .\n"
"                                   .         ;  \n"
"      .              .              ;%     ;;   \n"
"        ,           ,                :;%  %;   \n"
"         :         ;                   :;%;'     .,   \n"
",.        %;     %;            ;        %;'    ,;\n"
"  ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
"   %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
"    ;%;      %;        ;%;        % ;%;  ,%;'\n"
"     `%;.     ;%;     %;'         `;%%;.%;'\n"
"      `:;%.    ;%%. %@;        %; ;@%;%'\n"
"         `:%;.  :;bd%;          %;@%;'\n"
"           `@%:.  :;%.         ;@@%;'   \n"
"             `@%.  `;@%.      ;@@%;      \n"
"               `@%%. `@%%    ;@@%;        \n"
"                 ;@%. :@%%  %@@%;       \n"
"                   %@bd%%%bd%%:;     \n"
"                     #@%%%%%:;;\n"
"                     %@@%%%::;\n"
"                     %@@@%(o);  . '         \n"
"                     %@@@o%;:(.,'         \n"
"                 `.. %@@@o%::;         \n"
"                    `)@@@o%::;         \n"
"                     %@@(o)::;        \n"
"                    .%@@@@%::;         \n"
"                    ;%@@@@%::;.          \n"
"                   ;%@@@@%%:;;;. \n"
"               ...;%@@@@@%%:;;;;,..   \n";
		std::cout << "complete ASCII tree write to [" << this->Target + "_shrubbery]" << std::endl;
	}
	else
	{
		std::cout << "cannot open file..."  << std::endl;
	}
	file.close();

}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &rhd)
{
	Target = rhd.Target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	;
}
