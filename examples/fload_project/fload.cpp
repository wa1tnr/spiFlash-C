// Adafruit SPI Flash FatFs Simple Datalogging Example
// Author: Tony DiCola
//
// Fri Aug  9 19:12:29 UTC 2019
// Modified: wa1tnr, 9 August 2019
//
// This is a simple example that opens a file and prints its
// entire contents to the serial monitor.  Note that
// you MUST have a flash chip that's formatted with a flash
// filesystem before running, and there should be some sort
// of text file on it to open and read.  See the fatfs_format
// example to perform this formatting, and the fatfs_datalogging
// example to write a simple text file.
//
// Usage:
// - Modify the pins and type of fatfs object in the config
//   section below if necessary (usually not necessary).
// - Upload this sketch to your M0 express board.
// - Open the serial monitor at 115200 baud.  You should see the
//   example start to run and messages printed to the monitor.
//   If you don't see anything close the serial monitor, press
//   the board reset buttton, wait a few seconds, then open the
//   serial monitor again.

#include <Arduino.h>
#include <SPI.h>
#include <SdFat.h>
#include <Adafruit_SPIFlash.h>

#if defined(__SAMD51__) || defined(NRF52840_XXAA)
  Adafruit_FlashTransport_QSPI flashTransport(PIN_QSPI_SCK, PIN_QSPI_CS, PIN_QSPI_IO0, PIN_QSPI_IO1, PIN_QSPI_IO2, PIN_QSPI_IO3);
#else
  #if (SPI_INTERFACES_COUNT == 1)
    Adafruit_FlashTransport_SPI flashTransport(SS, &SPI);
  #else
    Adafruit_FlashTransport_SPI flashTransport(SS1, &SPI1);
  #endif
#endif

Adafruit_SPIFlash flash(&flashTransport);

// file system object from SdFat
FatFileSystem fatfs;

// Configuration for the file to open and read:
#define FILE_NAME      "/forth/ascii_xfer_a001.txt"

#define SUPL_FILES
#undef SUPL_FILES

#ifndef SUPL_FILES
File thisFile; // external to any function

void fl_setup(void) {
  delay(100); // dummy
}
#endif

#ifdef SUPL_FILES
#include "hidden-extra.h"
#endif
