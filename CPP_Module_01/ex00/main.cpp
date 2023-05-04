/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:32:03 by ejachoi           #+#    #+#             */
/*   Updated: 2023/05/04 15:32:04 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
    Zombie  stack("stack1");
    Zombie  *heap;
    heap = newZombie("heap");
    randomChump("stack2");

    stack.announce();
    heap->announce();
    delete(heap);
    return 0;
}
