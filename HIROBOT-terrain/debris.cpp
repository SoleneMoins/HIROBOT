#include"debris.h"

debris::debris():element{nullptr}
{}

/**
 * Constructeur de debris avec une position
 */
debris::debris(position*p):element{p}
{}
