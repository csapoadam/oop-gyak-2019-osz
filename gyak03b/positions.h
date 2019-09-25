#pragma once


enum class POSITIONS {
	forward,
	midfield,
	defense,
	goalkeeper,
	none
};

std::string stringify_position(POSITIONS p) {
	switch (p) {
	case POSITIONS::forward:
		std::cout << "forward";
		break;
	case POSITIONS::midfield:
		return "midfielder";
		break;
	case POSITIONS::defense:
		return "defender";
		break;
	case POSITIONS::goalkeeper:
		return "goalkeeper";
		break;
	default:
		return "role that is undefined";
		break;
	}
}