/*
 * Pyramid.h
 *
 *  Created on: Jun 26, 2013
 *      Author: goldman
 */

#ifndef PYRAMID_H_
#define PYRAMID_H_

#include "Population.h"
#include "Evaluation.h"
#include "Util.h"
#include "HillClimb.h"
#include "Configuration.h"
#include "Optimizer.h"

class Pyramid: public Optimizer
{
private:
	vector<Population> pops;

	bool add_unique(Random& rand, const vector<bool> & solution, size_t level);
	size_t length;
public:
	std::unordered_set<vector<bool>> seen;
	Pyramid(Configuration& config):
		length(config.get<int>("length")) {}
	void climb(Random& rand, vector<bool> & solution, float & fitness, Evaluator& evaluator);
	void optimize(Random& rand, Evaluator& evaluator, Configuration& config) override;
};

#endif /* PYRAMID_H_ */
