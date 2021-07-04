#ifndef CONSTANTS_H
#define CONSTANTS_H

const static int SCREEN_SIZE_W = 1920;
const static int SCREEN_SIZE_H = 1080;

const static int BOID_SPEED = 150;

const static int NUMBER_OF_BOIDS = 20;

const static float COHESION_RANGE = 250;
const static float ALIGNMENT_RANGE = 50;
const static float SEPARATION_RANGE = 50;

const static float COHESION_STRENGTH = .3;
const static float ALIGNMENT_STRENGTH = .3;
const static float SEPARATION_STRENGTH = .3;
#endif // !CONSTANTS_H