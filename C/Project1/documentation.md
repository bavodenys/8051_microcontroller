# Programming the STC89 Microcontroller with stcgal

## Step 1: Install the Programming Tool
1. Make sure **Python 3** is installed.  
2. Install `stcgal`:  
   ```bash
   pip install stcgal
   ```  
3. Verify the installation:  
   ```bash
   stcgal --help
   ```

---

## Step 2: Connect the Hardware
- Connect the **STC89C52** board to your computer via a USB-to-serial adapter (Linux: usually `/dev/ttyUSB0`).  
- Ensure the board is powered and has a working crystal oscillator (typically **11.952 MHz**).  

---

## Step 3: Compile the C Program
1. Compile the C source file:  
   ```bash
   sdcc blink.c
   ```
2. Convert the output to Intel HEX format:  
   ```bash
   packihx blink.ihx > blink.hex
   ```

---

## Step 4: Attempt Initial Programming
Flash the microcontroller with:  
```bash
stcgal -p /dev/ttyUSB0 -P stc89 blink.hex
```

Expected output should detect the MCU, e.g.:  
- Model: `STC89C52RC/LE52RC`  
- Flash: 8 KB  
- Target frequency: ~11.952 MHz  

---

## Step 5: Troubleshoot Baud Rate Issues
- Default baud rate is **115200**.  
- With a ~12 MHz crystal, you may see:  
  ```
  WARNING: baudrate error is 8.07%
  Protocol error
  ```
- **Cause:** The default baud rate is too high for the crystal frequency.  

---

## Step 6: Adjust the Baud Rate
Use a slower baud rate, or specify the exact crystal frequency:  

```bash
stcgal -p /dev/ttyUSB0 -P stc89 -b 9600 blink.hex
```
or  
```bash
stcgal -p /dev/ttyUSB0 -P stc89 --freq 11952000 blink.hex
```

---

## Step 7: Flash the MCU
When successful, `stcgal` will load the `.hex` file:  
```
Loading flash: 155 bytes (Intel HEX)
done
```

---

## Step 8: Test the Program
- Press the **reset/white button** on the board.  
- The program runs (e.g., LED blinking from `blink.hex`).  
- If your program uses a display, it should now show output.  

---

## Step 9: Key Takeaways
- Always match the **baud rate** to the **crystal frequency**.  
- If programming fails, lower the baud rate or specify the exact frequency.  
- The reset button usually starts the user program after flashing.  
