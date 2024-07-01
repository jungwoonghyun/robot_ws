#include "esp32_init.hpp"

void openEsp32Device(char* dev, int* fd){
    struct termios newtio;
	*fd = open(dev, O_RDWR | O_NOCTTY);
    //fd = open( "/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NONBLOCK );
	if (*fd < 0)
	{
		fprintf(stderr, "Can't open file '%s': %s\r\n", dev, strerror(errno));
		exit(EXIT_FAILURE);
	}

    memset(&newtio,0,sizeof(newtio));

    newtio.c_cflag = B115200;
    newtio.c_cflag |= CS8;
    newtio.c_cflag |= CLOCAL;
    newtio.c_cflag |= CREAD;
    newtio.c_iflag = IGNPAR;
    //newtio.c_iflag = ICRNL;
    newtio.c_oflag = 0;
    newtio.c_lflag = 0;
    newtio.c_cc[VTIME] = 0;
    newtio.c_cc[VMIN] = 0;

    tcflush(*fd,TCIFLUSH);
    tcsetattr(*fd,TCSANOW,&newtio);
}

void Esp32ReadData(int* fd, uint8_t* buf)
{
  read(*fd, buf, sizeof(buf));
}

void Esp32WriteData(int* fd, uint8_t* buf)
{
  write(*fd, buf, 1);
}