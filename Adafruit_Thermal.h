#pragma once

#include "Arduino.h"

// Internal character sets used with ESC R n
#define CHARSET_USA 0           //!< American character set
#define CHARSET_FRANCE 1        //!< French character set
#define CHARSET_GERMANY 2       //!< German character set
#define CHARSET_UK 3            //!< UK character set
#define CHARSET_DENMARK1 4      //!< Danish character set 1
#define CHARSET_SWEDEN 5        //!< Swedish character set
#define CHARSET_ITALY 6         //!< Italian character set
#define CHARSET_SPAIN1 7        //!< Spanish character set 1
#define CHARSET_JAPAN 8         //!< Japanese character set
#define CHARSET_NORWAY 9        //!< Norwegian character set
#define CHARSET_DENMARK2 10     //!< Danish character set 2
#define CHARSET_SPAIN2 11       //!< Spanish character set 2
#define CHARSET_LATINAMERICA 12 //!< Latin American character set
#define CHARSET_KOREA 13        //!< Korean character set
#define CHARSET_SLOVENIA 14     //!< Slovenian character set
#define CHARSET_CROATIA 14      //!< Croatian character set
#define CHARSET_CHINA 15        //!< Chinese character set

// Character code tables used with ESC t n
#define CODEPAGE_CP437 0    //!< USA, Standard Europe character code table
#define CODEPAGE_KATAKANA 1 //!< Katakana (Japanese) character code table
#define CODEPAGE_CP850 2    //!< Multilingual character code table
#define CODEPAGE_CP860 3    //!< Portuguese character code table
#define CODEPAGE_CP863 4    //!< Canadian-French character code table
#define CODEPAGE_CP865 5    //!< Nordic character code table
#define CODEPAGE_WCP1251 6  //!< Cyrillic character code table
#define CODEPAGE_CP866 7    //!< Cyrillic #2 character code table
#define CODEPAGE_MIK 8      //!< Cyrillic/Bulgarian character code table
#define CODEPAGE_CP755 9    //!< East Europe, Latvian 2 character code table
#define CODEPAGE_IRAN 10    //!< Iran 1 character code table
#define CODEPAGE_CP862 15   //!< Hebrew character code table
#define CODEPAGE_WCP1252 16 //!< Latin 1 character code table
#define CODEPAGE_WCP1253 17 //!< Greek character code table
#define CODEPAGE_CP852 18   //!< Latin 2 character code table
#define CODEPAGE_CP858 19 //!< Multilingual Latin 1 + Euro character code table
#define CODEPAGE_IRAN2 20 //!< Iran 2 character code table
#define CODEPAGE_LATVIAN 21     //!< Latvian character code table
#define CODEPAGE_CP864 22       //!< Arabic character code table
#define CODEPAGE_ISO_8859_1 23  //!< West Europe character code table
#define CODEPAGE_CP737 24       //!< Greek character code table
#define CODEPAGE_WCP1257 25     //!< Baltic character code table
#define CODEPAGE_THAI 26        //!< Thai character code table
#define CODEPAGE_CP720 27       //!< Arabic character code table
#define CODEPAGE_CP855 28       //!< Cyrillic character code table
#define CODEPAGE_CP857 29       //!< Turkish character code table
#define CODEPAGE_WCP1250 30     //!< Central Europe character code table
#define CODEPAGE_CP775 31       //!< Baltic character code table
#define CODEPAGE_WCP1254 32     //!< Turkish character code table
#define CODEPAGE_WCP1255 33     //!< Hebrew character code table
#define CODEPAGE_WCP1256 34     //!< Arabic character code table
#define CODEPAGE_WCP1258 35     //!< Vietnam character code table
#define CODEPAGE_ISO_8859_2 36  //!< Latin 2 character code table
#define CODEPAGE_ISO_8859_3 37  //!< Latin 3 character code table
#define CODEPAGE_ISO_8859_4 38  //!< Baltic character code table
#define CODEPAGE_ISO_8859_5 39  //!< Cyrillic character code table
#define CODEPAGE_ISO_8859_6 40  //!< Arabic character code table
#define CODEPAGE_ISO_8859_7 41  //!< Greek character code table
#define CODEPAGE_ISO_8859_8 42  //!< Hebrew character code table
#define CODEPAGE_ISO_8859_9 43  //!< Turkish character code table
#define CODEPAGE_ISO_8859_15 44 //!< Latin 3 character code table
#define CODEPAGE_THAI2 45       //!< Thai 2 character code page
#define CODEPAGE_CP856 46       //!< Hebrew character code page
#define CODEPAGE_CP874 47       //!< Thai character code page

/*!
 * Barcode types used with GS k m
 */
enum barcodes {
  UPC_A,   /**< UPC-A barcode system. 11-12 char */
  UPC_E,   /**< UPC-E barcode system. 11-12 char */
  EAN13,   /**< EAN13 (JAN13) barcode system. 12-13 char */
  EAN8,    /**< EAN8 (JAN8) barcode system. 7-8 char */
  CODE39,  /**< CODE39 barcode system. 1<=num of chars */
  ITF,     /**< ITF barcode system. 1<=num of chars, must be an even number */
  CODABAR, /**< CODABAR barcode system. 1<=num<=255 */
  CODE93,  /**< CODE93 barcode system. 1<=num<=255 */
  CODE128, /**< CODE128 barcode system. 2<=num<=255 */
};

// ASCII codes used by some of the printer config commands:
#define ASCII_TAB '\t' //!< Horizontal tab
#define ASCII_LF '\n'  //!< Line feed
#define ASCII_FF '\f'  //!< Form feed
#define ASCII_CR '\r'  //!< Carriage return
#define ASCII_DC2 18   //!< Device control 2
#define ASCII_ESC 27   //!< Escape
#define ASCII_FS 28    //!< Field separator
#define ASCII_GS 29    //!< Group separator

#define BYTE_TIME (((11L * 1000000L) + (9600 / 2)) / 9600)

// === Character commands ===
#define FONT_MASK (1 << 0) //!< Select character font A or B
#define INVERSE_MASK                                                           \
  (1 << 1) //!< Turn on/off white/black reverse printing mode. Not in 2.6.8
           //!< firmware (see inverseOn())
#define UPDOWN_MASK (1 << 2)        //!< Turn on/off upside-down printing mode
#define BOLD_MASK (1 << 3)          //!< Turn on/off bold printing mode
#define DOUBLE_HEIGHT_MASK (1 << 4) //!< Turn on/off double-height printing mode
#define DOUBLE_WIDTH_MASK (1 << 5)  //!< Turn on/off double-width printing mode
#define STRIKE_MASK (1 << 6)        //!< Turn on/off deleteline mode

/*!
 * Driver for the thermal printer
 */
template <class S>
class Adafruit_Thermal : public Print {

public:
  // IMPORTANT: constructor syntax has changed from prior versions
  // of this library.  Please see notes in the example code!
  /*!
   * @brief Thermal constructor
   * @param s Serial stream
   * @param dtr Data Terminal Ready control
   */
  Adafruit_Thermal(S *s, int dtr=255) : stream(s), dtrPin(dtr) {
    dtrEnabled = (dtr != 255);
  }

  size_t write(uint8_t c) {
    if (c != 13) { // Strip carriage returns
      timeoutWait();
      stream->write(c);
      unsigned long d = BYTE_TIME;
      if ((c == '\n') || (column == maxColumn)) { // If newline or wrap
        d += (prevByte == '\n') ? ((charHeight + lineSpacing) * dotFeedTime)
                                : // Feed line
                ((charHeight * dotPrintTime) +
                  (lineSpacing * dotFeedTime)); // Text line
        column = 0;
        c = '\n'; // Treat wrap as newline on next pass
      } else {
        column++;
      }
      timeoutSet(d);
      prevByte = c;
    }

    return 1;
  }

  void begin(uint16_t version=268) {
    firmware = version;

    // The printer can't start receiving data immediately upon power up --
    // it needs a moment to cold boot and initialize.  Allow at least 1/2
    // sec of uptime before printer can receive data.
    timeoutSet(500000L);

    wake();
    reset();

    setHeatConfig();

    // Enable DTR pin if requested
    if (dtrPin < 255) {
      pinMode(dtrPin, INPUT_PULLUP);
      writeBytes(ASCII_GS, 'a', (1 << 5));
      dtrEnabled = true;
    }

    dotPrintTime = 30000; // See comments near top of file for
    dotFeedTime = 2100;   // an explanation of these values.
    maxChunkHeight = 255;
  }
    /*!
     * @brief Disables bold text
     */
    void boldOff() { unsetPrintMode(BOLD_MASK); }
    /*!
     * @brief Enables bold text
     */
    void boldOn() { setPrintMode(BOLD_MASK); }
    /*!
     * @brief Disables double-height text
     */
    void doubleHeightOff() { unsetPrintMode(DOUBLE_HEIGHT_MASK); }
    /*!
     * @brief Enables double-height text
     */
    void doubleHeightOn() { setPrintMode(DOUBLE_HEIGHT_MASK); }
    /*!
     * @brief Disables double-width text
     */
    void doubleWidthOff() { unsetPrintMode(DOUBLE_WIDTH_MASK); }
    /*!
     * @brief Enables double-width text
     */
    void doubleWidthOn() { setPrintMode(DOUBLE_WIDTH_MASK); }
    /*!
     * @brief Feeds by the specified number of lines 
     * @param x How many lines to feed 
     */
    void feed(uint8_t x=1) {
      if (firmware >= 264) {
        writeBytes(ASCII_ESC, 'd', x);
        timeoutSet(dotFeedTime * charHeight);
        prevByte = '\n';
        column = 0;
      } else {
        while (x--)
          write('\n'); // Feed manually; old firmware feeds excess lines
      }
    }
    /*!
     * @brief Feeds by the specified number of individual pixel rows 
     * @param rows How many rows to feed
     */
    void feedRows(uint8_t rows) {
      writeBytes(ASCII_ESC, 'J', rows);
      timeoutSet(rows * dotFeedTime);
      prevByte = '\n';
      column = 0;
    }
    /*!
     * @brief Flush data pending in the printer 
     */
    void flush() { writeBytes(ASCII_FF); }
    /*!
     * @brief Disables white/black reverse printing mode
     */
    void inverseOff() {
      if (firmware >= 268) {
        writeBytes(ASCII_GS, 'B', 0);
      } else {
        unsetPrintMode(INVERSE_MASK);
      }
    }

    /*!
     * @brief Enables white/black reverse printing mode
     */
    void inverseOn() {
      if (firmware >= 268) {
        writeBytes(ASCII_GS, 'B', 1);
      } else {
        setPrintMode(INVERSE_MASK);
      }
    }

    /*!
     * @brief Set the justification of text
     * @param value justification, must be JUSTIFY_LEFT, JUSTIFY_CENTER, JUSTIFY_RIGHT
     */
    void justify(char value) {
      uint8_t pos = 0;

      switch (toupper(value)) {
      case 'L':
        pos = 0;
        break;
      case 'C':
        pos = 1;
        break;
      case 'R':
        pos = 2;
        break;
      }

      writeBytes(ASCII_ESC, 'a', pos);
    }
    /*!
     * @brief Put the printer into an offline state. No other commands can be sent until an online call is made
     */
    void offline() { writeBytes(ASCII_ESC, '=', 0); }

    /*!
     * @brief Put the printer into an online state after previously put offline
     */
    void online() { writeBytes(ASCII_ESC, '=', 1); }

    /*!
     * @brief Print a barcode
     * @param text The specified text/number (the meaning varies based on the type of barcode) and type to write to the barcode
     * @param type Value from the datasheet or class-level variables like UPC-A. Note the type value changes depending on the firmware version so use class-level values where possible
     */
    void printBarcode(const char *text, uint8_t type) {
      feed(1); // Recent firmware can't print barcode w/o feed first???
      if (firmware >= 264)
        type += 65;
      writeBytes(ASCII_GS, 'H', 2);    // Print label below barcode
      writeBytes(ASCII_GS, 'w', 3);    // Barcode width 3 (0.375/1.0mm thin/thick)
      writeBytes(ASCII_GS, 'k', type); // Barcode type (listed in .h file)
      if (firmware >= 264) {
        int len = strlen(text);
        if (len > 255)
          len = 255;
        writeBytes(len); // Write length byte
        for (uint8_t i = 0; i < len; i++)
          writeBytes(text[i]); // Write string sans NUL
      } else {
        uint8_t c, i = 0;
        do { // Copy string + NUL terminator
          writeBytes(c = text[i++]);
        } while (c);
      }
      timeoutSet((barcodeHeight + 40) * dotPrintTime);
      prevByte = '\n';
    }
    /*!
     * @brief Prints a bitmap
     * @param w Width of the image in pixels
     * @param h Height of the image in pixels
     * @param bitmap Bitmap data, from a file.
     * @param fromProgMem
     */
    void printBitmap(int w, int h, const uint8_t *bitmap, bool fromProgMem=true) {
      int rowBytes, rowBytesClipped, rowStart, chunkHeight, chunkHeightLimit, x, y,
          i;

      rowBytes = (w + 7) / 8; // Round up to next byte boundary
      rowBytesClipped = (rowBytes >= 48) ? 48 : rowBytes; // 384 pixels max width

      // Est. max rows to write at once, assuming 256 byte printer buffer.
      if (dtrEnabled) {
        chunkHeightLimit = 255; // Buffer doesn't matter, handshake!
      } else {
        chunkHeightLimit = 256 / rowBytesClipped;
        if (chunkHeightLimit > maxChunkHeight)
          chunkHeightLimit = maxChunkHeight;
        else if (chunkHeightLimit < 1)
          chunkHeightLimit = 1;
      }

      for (i = rowStart = 0; rowStart < h; rowStart += chunkHeightLimit) {
        // Issue up to chunkHeightLimit rows at a time:
        chunkHeight = h - rowStart;
        if (chunkHeight > chunkHeightLimit)
          chunkHeight = chunkHeightLimit;

        writeBytes(ASCII_DC2, '*', chunkHeight, rowBytesClipped);

        for (y = 0; y < chunkHeight; y++) {
          for (x = 0; x < rowBytesClipped; x++, i++) {
            timeoutWait();
            stream->write(fromProgMem ? pgm_read_byte(bitmap + i) : *(bitmap + i));
          }
          i += rowBytes - rowBytesClipped;
        }
        timeoutSet(chunkHeight * dotPrintTime);
      }
      prevByte = '\n';
    }

    /*!
     * @brief Prints a bitmap
     * @param w Width of the image in pixels
     * @param h Height of the image in pixels
     * @param fromStream Stream to get bitmap data from
     */
    void printBitmap(int w, int h, Stream *fromStream) {
      int rowBytes, rowBytesClipped, rowStart, chunkHeight, chunkHeightLimit, x, y,
          i, c;

      rowBytes = (w + 7) / 8; // Round up to next byte boundary
      rowBytesClipped = (rowBytes >= 48) ? 48 : rowBytes; // 384 pixels max width

      // Est. max rows to write at once, assuming 256 byte printer buffer.
      if (dtrEnabled) {
        chunkHeightLimit = 255; // Buffer doesn't matter, handshake!
      } else {
        chunkHeightLimit = 256 / rowBytesClipped;
        if (chunkHeightLimit > maxChunkHeight)
          chunkHeightLimit = maxChunkHeight;
        else if (chunkHeightLimit < 1)
          chunkHeightLimit = 1;
      }

      for (rowStart = 0; rowStart < h; rowStart += chunkHeightLimit) {
        // Issue up to chunkHeightLimit rows at a time:
        chunkHeight = h - rowStart;
        if (chunkHeight > chunkHeightLimit)
          chunkHeight = chunkHeightLimit;

        writeBytes(ASCII_DC2, '*', chunkHeight, rowBytesClipped);

        for (y = 0; y < chunkHeight; y++) {
          for (x = 0; x < rowBytesClipped; x++) {
            while ((c = fromStream->read()) < 0)
              ;
            timeoutWait();
            stream->write((uint8_t)c);
          }
          for (i = rowBytes - rowBytesClipped; i > 0; i--) {
            while ((c = fromStream->read()) < 0)
              ;
          }
        }
        timeoutSet(chunkHeight * dotPrintTime);
      }
      prevByte = '\n';
    }

    /*!
     * @brief Prints a bitmap
     * @param fromStream Stream to get bitmap data from
     */
    void printBitmap(Stream *fromStream) {
      uint8_t tmp;
      uint16_t width, height;

      tmp = fromStream->read();
      width = (fromStream->read() << 8) + tmp;

      tmp = fromStream->read();
      height = (fromStream->read() << 8) + tmp;

      printBitmap(width, height, fromStream);
    }

    /*!
     * @brief Sets text to normal mode
     */ 
    void normal() {
      printMode = 0;
      writePrintMode();
    }

    /*!
     * @brief Reset the printer
     */
    void reset() {
      writeBytes(ASCII_ESC, '@'); // Init command
      prevByte = '\n';            // Treat as if prior line is blank
      column = 0;
      maxColumn = 32;
      charHeight = 24;
      lineSpacing = 6;
      barcodeHeight = 50;

      if (firmware >= 264) {
        // Configure tab stops on recent printers
        writeBytes(ASCII_ESC, 'D'); // Set tab stops...
        writeBytes(4, 8, 12, 16);   // ...every 4 columns,
        writeBytes(20, 24, 28, 0);  // 0 marks end-of-list.
      }
    }
    /*!
     * @brief Sets the barcode height
     * @param val Desired height of the barcode
     */
    void setBarcodeHeight(uint8_t val=50) { // Default is 50
      if (val < 1)
        val = 1;
      barcodeHeight = val;
      writeBytes(ASCII_GS, 'h', val);
    }
    /*!
     * @brief Sets the font
     * @param font Desired font, either A or B
     */
    void setFont(char font='A') {
      switch (toupper(font)) {
      case 'B':
        setPrintMode(FONT_MASK);
        break;
      case 'A':
      default:
        unsetPrintMode(FONT_MASK);
      }
    }
    /*!
     * @brief Sets the character spacing
     * @param spacing Desired character spacing
     */
    void setCharSpacing(int spacing=0) {
      writeBytes(ASCII_ESC, ' ', spacing);
    }
    /*!
     * @brief Sets the character set
     * @param val Value of the desired character set
     */
    void setCharset(uint8_t val=0) {
      if (val > 15)
        val = 15;
      writeBytes(ASCII_ESC, 'R', val);
    }
    /*!
     * @brief Sets character code page
     * @param val Value of the desired character code page
     */
    void setCodePage(uint8_t val=0) {
      if (val > 47)
        val = 47;
      writeBytes(ASCII_ESC, 't', val);
    }
    /*!
     * @brief Sets the default settings
     */
    void setDefault() {
      online();
      justify('L');
      inverseOff();
      doubleHeightOff();
      setLineHeight(30);
      boldOff();
      underlineOff();
      setBarcodeHeight(50);
      setSize('s');
      setCharset();
      setCodePage();
    }
    /*!
     * @brief Sets the line height
     * @param val Desired line height
     */
    void setLineHeight(int val=30) {
      if (val < 24)
        val = 24;
      lineSpacing = val - 24;

      // The printer doesn't take into account the current text height
      // when setting line height, making this more akin to inter-line
      // spacing.  Default line spacing is 30 (char height of 24, line
      // spacing of 6).
      writeBytes(ASCII_ESC, '3', val);
    }

    /*!
     * @brief Set max rows to write
     * @param val Max rows to write
     */
    void setMaxChunkHeight(int val=256) { maxChunkHeight = val; }
    /*!
     * @brief Sets text size
     * @param value Text size
     */
    void setSize(char value) {
      uint8_t size;

      switch (toupper(value)) {
      default: // Small: standard width and height
        // size = 0x00;
        // charHeight = 24;
        // maxColumn = 32;
        doubleWidthOff();
        doubleHeightOff();
        break;
      case 'M': // Medium: double height
        // size = 0x01;
        // charHeight = 48;
        // maxColumn = 32;
        doubleHeightOn();
        doubleWidthOff();
        break;
      case 'L': // Large: double width and height
        // size = 0x11;
        // charHeight = 48;
        // maxColumn = 16;
        doubleHeightOn();
        doubleWidthOn();
        break;
      }

      // writeBytes(ASCII_GS, '!', size);
      // prevByte = '\n'; // Setting the size adds a linefeed
    }
    /*!
     * @brief Sets print and feed speed
     * @param p print speed
     * @param f feed speed
     */
    void setTimes(unsigned long p, unsigned long f) {
      dotPrintTime = p;
      dotFeedTime = f;
    }

    /*!
     * @brief Sets print head heating configuration
     * @param dots max printing dots, 8 dots per increment
     * @param time heating time, 10us per increment
     * @param interval heating interval, 10 us per increment
     */
    void setHeatConfig(uint8_t dots=11, uint8_t time=120, uint8_t interval=40) {
      writeBytes(ASCII_ESC, '7');       // Esc 7 (print settings)
      writeBytes(dots, time, interval); // Heating dots, heat time, heat interval
    }
    /*!
     * @brief Sets print density
     * @param density printing density
     * @param breakTime printing break time
     */
    void setPrintDensity(uint8_t density=10, uint8_t breakTime=2) {
      writeBytes(ASCII_DC2, '#', (density << 5) | breakTime);
    }
    /*!
     * @brief Puts the printer into a low-energy state immediately
     */
    void sleep() {
      sleepAfter(1); // Can't be 0, that means 'don't sleep'
    }

    /*!
     * @brief Puts the printer into a low-energe state after the given number of seconds
     * @param seconds How many seconds to wait until sleeping
     */
    void sleepAfter(uint16_t seconds) {
      if (firmware >= 264) {
        writeBytes(ASCII_ESC, '8', seconds, seconds >> 8);
      } else {
        writeBytes(ASCII_ESC, '8', seconds);
      }
    }

    /*!
     * @brief Disables delete line mode
     */ 
    void strikeOff() { unsetPrintMode(STRIKE_MASK); }
    /*!
     * @brief Enables delete line mode
     */
    void strikeOn() { setPrintMode(STRIKE_MASK); }
    /*!
     * @brief Sends tab to device
     */
    void tab() {
      writeBytes(ASCII_TAB);
      column = (column + 4) & 0b11111100;
    }
    /*!
     * @brief Prints test text
     */
    void test() {
      println(F("Hello World!"));
      feed(2);
    }

    /*!
     * @brief Prints test page
     */
    void testPage() {
      writeBytes(ASCII_DC2, 'T');
      timeoutSet(dotPrintTime * 24 * 26 + // 26 lines w/text (ea. 24 dots high)
                dotFeedTime *
                    (6 * 26 + 30)); // 26 text lines (feed 6 dots) + blank line
    }

    /*!
     * @brief Sets the estimated completion time for a just-issued task
     * @param x Estimated completion time
     */
    void timeoutSet(unsigned long x) {
      if (!dtrEnabled)
        resumeTime = micros() + x;
    }

    /*!
     * @brief Waits for the prior task to complete 
     */
    void timeoutWait() {
      if (dtrEnabled) {
        while (digitalRead(dtrPin) == HIGH) {
          yield();
        };
      } else {
        while ((long)(micros() - resumeTime) < 0L) {
          yield();
        }; // (syntax is rollover-proof)
      }
    }

    /*!
     * @brief Disables underline
     */
    void underlineOff() { writeBytes(ASCII_ESC, '-', 0); }
    /*!
     * @brief Enables underline
     * @param weight Weight of the line
     */
    void underlineOn(uint8_t weight=1) {
      if (weight > 2)
        weight = 2;
      writeBytes(ASCII_ESC, '-', weight);
    }
    /*!
     * @brief Disables upside-down text mode
     */
    void upsideDownOff() {
      if (firmware >= 268) {
        writeBytes(ASCII_ESC, '{', 0);
      } else {
        unsetPrintMode(UPDOWN_MASK);
      }
    }

    /*!
     * @brief Enables upside-down text mode
     */
    void upsideDownOn() {
      if (firmware >= 268) {
        writeBytes(ASCII_ESC, '{', 1);
      } else {
        setPrintMode(UPDOWN_MASK);
      }
    }

    /*!
     * @brief Wakes device that was in sleep mode
     */
    void wake() {
      timeoutSet(0);   // Reset timeout counter
      writeBytes(255); // Wake
      if (firmware >= 264) {
        delay(50);
        writeBytes(ASCII_ESC, '8', 0, 0); // Sleep off (important!)
      } else {
        // Datasheet recommends a 50 mS delay before issuing further commands,
        // but in practice this alone isn't sufficient (e.g. text size/style
        // commands may still be misinterpreted on wake).  A slightly longer
        // delay, interspersed with NUL chars (no-ops) seems to help.
        for (uint8_t i = 0; i < 10; i++) {
          writeBytes(0);
          timeoutSet(10000L);
        }
      }
    }

    bool hasPaper() {
      if (firmware >= 264) {
        writeBytes(ASCII_ESC, 'v', 0);
      } else {
        writeBytes(ASCII_GS, 'r', 0);
      }

      int status = -1;
      for (uint8_t i = 0; i < 10; i++) {
        if (stream->available()) {
          status = stream->read();
          break;
        }
        delay(100);
      }

      return !(status & 0b00000100);
    }


private:
  S *stream;

  uint8_t printMode,
      prevByte,      // Last character issued to printer
      column,        // Last horizontal column printed
      maxColumn,     // Page width (output 'wraps' at this point)
      charHeight,    // Height of characters, in 'dots'
      lineSpacing,   // Inter-line spacing (not line height), in dots
      barcodeHeight, // Barcode height in dots, not including text
      maxChunkHeight,
      dtrPin;         // DTR handshaking pin (experimental)
  uint16_t firmware;  // Firmware version
  boolean dtrEnabled; // True if DTR pin set & printer initialized
  unsigned long
      resumeTime,   // Wait until micros() exceeds this before sending byte
      dotPrintTime, // Time to print a single dot line, in microseconds
      dotFeedTime;  // Time to feed a single dot line, in microseconds
  
  void writeBytes(uint8_t a) {
    timeoutWait();
    stream->write(a);
    timeoutSet(BYTE_TIME);
  }

  void writeBytes(uint8_t a, uint8_t b) {
    timeoutWait();
    stream->write(a);
    stream->write(b);
    timeoutSet(2 * BYTE_TIME);
  }

  void writeBytes(uint8_t a, uint8_t b, uint8_t c) {
    timeoutWait();
    stream->write(a);
    stream->write(b);
    stream->write(c);
    timeoutSet(3 * BYTE_TIME);
  }

  void writeBytes(uint8_t a, uint8_t b, uint8_t c, uint8_t d) {
    timeoutWait();
    stream->write(a);
    stream->write(b);
    stream->write(c);
    stream->write(d);
    timeoutSet(4 * BYTE_TIME);
  }

  void setPrintMode(uint8_t mask) {
    printMode |= mask;
    writePrintMode();
    adjustCharValues(printMode);
    // charHeight = (printMode & DOUBLE_HEIGHT_MASK) ? 48 : 24;
    // maxColumn = (printMode & DOUBLE_WIDTH_MASK) ? 16 : 32;
  }

  void unsetPrintMode(uint8_t mask) {
    printMode &= ~mask;
    writePrintMode();
    adjustCharValues(printMode);
    // charHeight = (printMode & DOUBLE_HEIGHT_MASK) ? 48 : 24;
    // maxColumn = (printMode & DOUBLE_WIDTH_MASK) ? 16 : 32;
  }

  void writePrintMode() {
    writeBytes(ASCII_ESC, '!', printMode);
  }

  void adjustCharValues(uint8_t printMode) {
    uint8_t charWidth;
    if (printMode & FONT_MASK) {
      // FontB
      charHeight = 17;
      charWidth = 9;
    } else {
      // FontA
      charHeight = 24;
      charWidth = 12;
    }
    // Double Width Mode
    if (printMode & DOUBLE_WIDTH_MASK) {
      maxColumn /= 2;
      charWidth *= 2;
    }
    // Double Height Mode
    if (printMode & DOUBLE_HEIGHT_MASK) {
      charHeight *= 2;
    }
    maxColumn = (384 / charWidth);
  }
};
