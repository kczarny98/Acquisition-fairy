#include <asf.h>

#define LED_PIN		IOPORT_CREATE_PIN(PORTD, 5)
#define BUTTON_PIN	IOPORT_CREATE_PIN(PORTE, 5)

int main (void)
{
	bool but_state;
	
	ioport_init();
	
	ioport_set_pin_dir(LED_PIN, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(BUTTON_PIN, IOPORT_DIR_INPUT);
	ioport_set_pin_mode(BUTTON_PIN, IOPORT_MODE_PULLUP);
	
	while(1) {
		but_state = !ioport_get_pin_level(BUTTON_PIN);
		
		if (but_state) {
			ioport_toggle_pin_level(LED_PIN);
			delay_ms(100);
		}
	}
}
