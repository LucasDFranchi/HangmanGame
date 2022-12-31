#include <iostream>

void DrawHangman(int mistakes){
	switch(mistakes){
		case 0: std::cout << "_________" << std::endl
					 << " |     | " << std::endl
					 << " | " << std::endl
					 << " | " << std::endl
					 << " | " << std::endl
					 << " | " << std::endl
					 << "``````````" << std::endl;
			break;
		case 1: std::cout << "_________" << std::endl
					 << " |     | " << std::endl
					 << " |   (   )" << std::endl
					 << " | " << std::endl
					 << " | " << std::endl
					 << " | " << std::endl
					 << "``````````" << std::endl;
			break;
		case 2: std::cout << "_________" << std::endl
					 << " |     | " << std::endl
					 << " |   (o_o)" << std::endl
					 << " |     " << std::endl
					 << " |     " << std::endl
					 << " | " << std::endl
					 << "``````````" << std::endl;
			break;
		case 3: std::cout << "_________" << std::endl
					 << " |     | " << std::endl
					 << " |   (o_o)" << std::endl
					 << " |     | " << std::endl
					 << " |     |" << std::endl
					 << " | " << std::endl
					 << "``````````" << std::endl;
			break;
		case 4: std::cout << "_________" << std::endl
					 << " |     | " << std::endl
					 << " |   (o_o)" << std::endl
					 << " |    _| " << std::endl
					 << " |     |" << std::endl
					 << " | " << std::endl
					 << "``````````" << std::endl;
			break;
		case 5: std::cout << "_________" << std::endl
					 << " |     | " << std::endl
					 << " |   (o_o)" << std::endl
					 << " |    _|_ " << std::endl
					 << " |     |" << std::endl
					 << " |     " << std::endl
					 << "``````````" << std::endl;
			break;
		case 6: std::cout << "_________" << std::endl
					 << " |     | " << std::endl
					 << " |   (o_o)" << std::endl
					 << " |    _|_ " << std::endl
					 << " |     |" << std::endl
					 << " |    / " << std::endl
					 << "``````````" << std::endl;
			break;
		case 7: std::cout << "_________" << std::endl
					 << " |     | " << std::endl
					 << " |   (O_O)" << std::endl
					 << " |    \\|/ " << std::endl
					 << " |     |" << std::endl
					 << " |    / \\" << std::endl
					 << "``````````" << std::endl;
			break;
		case 8: std::cout << "_________" << std::endl
					 << " |     | " << std::endl
					 << " |   (x_x)" << std::endl
					 << " |     | " << std::endl
					 << " |    /|\\" << std::endl
					 << " |    / \\" << std::endl
					 << " ````\\" << std::endl
					 << "      \\" << std::endl;
			break;
        default:
            std::cout << " " << std::endl;
	}
	return;
}
