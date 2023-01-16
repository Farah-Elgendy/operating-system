# Producer Consumer problem

# Description 
 This code develops the producer consumer problem using semaphores and mutual exclusion , there is three semaphores:
  1. The first one to achieve the mutual exclusion between the producer and the consumer.
  2. The second one to block the producer from producing if the buffer is full.
  3. The third is to block the consumer if the buffer is already empty.
  
# Requirements
you should install "sudo apt install g++" , "sudo apt install gcc" , "sudo apt-get install bison flex " 
just type "make" on the terminal to compile the project and then write ./producer and ./consumer to run it.
