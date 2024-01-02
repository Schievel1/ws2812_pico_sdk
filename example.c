#include "pico/stdlib.h"
#include "bsp/board.h"
#include "WS2812.pio.h"
#include "ws2812.h"

#define LED_PIN 2
#define NUM_LEDS 3
#define STATE_MACHINE 0
#define IS_RGBW false

struct WS2812* led_strip;

int main(void) {
  board_init();
  stdio_init_all();

  // Create a WS2812 object
  led_strip = ws2812_initialize(pio0, STATE_MACHINE, LED_PIN, NUM_LEDS, IS_RGBW);

  // fill the whole LED strip with white
  ws2812_fill(led_strip, ws2812_urgb_grbu32(255, 255, 255));
  // write the data do the strip
  ws2812_show(led_strip);

  while (1) {
    // set first LED to red
    ws2812_set_led(led_strip, 0, ws2812_urgb_grbu32(255, 0, 0));
    // set second LED to green
    ws2812_set_led(led_strip, 1, ws2812_urgb_grbu32(0, 255, 0));
    // set third LED to blue
    ws2812_set_led(led_strip, 2, ws2812_urgb_grbu32(0, 0, 255));
    // write the data do the strip
    ws2812_show(led_strip);
    sleep_ms(1000);
  }
}
