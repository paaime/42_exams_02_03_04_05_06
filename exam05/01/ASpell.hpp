/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:58:48 by hthomas           #+#    #+#             */
/*   Updated: 2021/06/29 15:47:10 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>

# include "ATarget.hpp"

using namespace std;

class ATarget;

class ASpell
{
private:
	string name;
	string effects;
	ASpell();
	ASpell& operator=(const ASpell& copy);
public:
	ASpell(string name, string effects):
	name(name), effects(effects)
	{}

	~ASpell();

	ASpell(const ASpell& copy)
	{
		name = copy.getName();
		effects = copy.getEffects();
	}

	string const &getName() const
	{
		return name;
	}

	string const &getEffects() const
	{
		return effects;
	}

	virtual ASpell *clone() const = 0;

	void launch(ATarget const& target);
};

#endif
