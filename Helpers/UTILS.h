/**
 *******************************************
 * @file    MemoryMap.h
 * @author  AHMED El_SAYED EL_SAID
 * @version 1.0
 * @date    9-7-2023
 * @brief   HEADER file for memory map of the ATMEGA32
 * @note    https://github.com/AHMED_SAYED
 *******************************************
 **/ 


#ifndef UTILS_H_
#define UTILS_H_

#define  SET_BIT(REG,BIT)  (REG=REG|(1<<BIT));
#define  CLR_BIT(REG,BIT)  (REG=REG&(~(1<<BIT)))
#define  TOG_BIT(REG,BIT)  (REG=REG^(1<<BIT)) 
#define  READ_BIT(REG,BIT) ((REG>>BIT)&1)

/*
@param register[in] the register to write
@param value[in]     the value to write form 
@param num_bits[in] the number of bits to write 
@brief write specific bits without affecting the other bits in the register
*the left part we preserve the higher bits of the register
*in the left part we get the lower bits of the value to be written
*then add them together and write the result back to the register
*/				 
#define WRITE_NUM_BITS(register, value, num_bits) (register = (register & ~((1 << num_bits) - 1)) | (value & ((1 << num_bits) - 1)))    




#endif /* UTILS_H_ */