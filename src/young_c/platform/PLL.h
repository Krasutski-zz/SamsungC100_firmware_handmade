/*
 * PLL.h
 *
 *  Created on: 25.07.2012
 *      Author: Admin
 */

#ifndef PLL_H_
#define PLL_H_


#define PLL_SET_DEFAULT PLL_CONTROL=0x0113
#define PLL_SET(div1, div2, mult) PLL_CONTROL=(PLL_CONTROL_DIV_P_MASK & div1)|(PLL_CONTROL_DIV_Q_MASK & div2)|(PLL_CONTROL_DIV_N_MASK & mult)

#endif /* PLL_H_ */
