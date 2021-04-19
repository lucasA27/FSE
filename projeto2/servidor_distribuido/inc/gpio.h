#ifndef __GPIO__
#define __GPIO__


#define AC1               23 
#define AC2               24
 
#define LAMP1             0 
#define LAMP2             1 
#define LAMP3             2 
#define LAMP4             3
 
#define SA1               21
#define SA2               22    
#define SA3               26
#define SA4               27
#define SA5               28
#define SA6               29

#define SP1               06
#define SP2               25


int leGpio(int ref);
void configuragpio();
void LigaGpio(int ref);
void DesligaGpio(int ref);
void desligarDispositivos();

#endif // ____GPIO____