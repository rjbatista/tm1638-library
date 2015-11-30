# TM1638/TM1640 library #

## A library for interacting an arduino with a TM1638 or a TM1640. ##
  * Support for the TM1638 and TM1640;
  * Support for common anode TM1638 module (QYF-TM1638);
  * Helper methods for displaying numbers in decimal, hexadecimal and binary;
  * Support for multiple chained TM1638;
  * Reading simultaneous button presses;
  * Support for dimming the display and LEDs;
  * Support for writing text;
  * Support for module in inverted position;
  * Examples for using the library with multiple TM1638 and with a TM1640.


## [Download latest version (v2.2.0)](https://drive.google.com/file/d/0B4oMHcU_S9TNM2ZGUFJ3bkhPTFU/view?usp=sharing) ##
###### (now forcibly via google drive as google deprecated downloads) ######

## [Library Reference](http://code.google.com/p/tm1638-library/wiki/Reference) ##

## Author ##
Ricardo Batista

Portugal

#### See: ####

[Library example usage video](http://www.youtube.com/watch?v=Vg3faVyApJY)

[Text scroller example video](http://www.youtube.com/watch?v=0B5GQWyF5SQ)

[Text scroller with several different TM1638 modules](http://www.youtube.com/watch?v=r8r8hdhNItU)

[TM1638 Display/LED module (Red display)](http://www.dx.com/p/81873?Utm_rid=68099021&Utm_source=affiliate)
[(older link)](http://www.dealextreme.com/p/81873?r=68099021)

[TM1638 Display/LED module (Green display)](http://www.dx.com/p/104329?Utm_rid=68099021&Utm_source=affiliate)
[(older link)](http://www.dealextreme.com/p/104329?r=68099021)

[TM1640 module](http://www.dx.com/p/104311?Utm_rid=68099021&Utm_source=affiliate)
[(older link)](http://www.dealextreme.com/p/104311?r=68099021)

##### This library is done as an hobby and it's free for everybody to use. #####
##### You can contribute to the project by _using it_ (drop me a line if you're doing something with it :) ), _submitting ideas_ or _donating_ via Paypal: #####
[![](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&encrypted=-----BEGIN%20PKCS7-----MIIHFgYJKoZIhvcNAQcEoIIHBzCCBwMCAQExggEwMIIBLAIBADCBlDCBjjELMAkGA1UEBhMCVVMxCzAJBgNVBAgTAkNBMRYwFAYDVQQHEw1Nb3VudGFpbiBWaWV3MRQwEgYDVQQKEwtQYXlQYWwgSW5jLjETMBEGA1UECxQKbGl2ZV9jZXJ0czERMA8GA1UEAxQIbGl2ZV9hcGkxHDAaBgkqhkiG9w0BCQEWDXJlQHBheXBhbC5jb20CAQAwDQYJKoZIhvcNAQEBBQAEgYBYItdz2UnIgUVAabUD0qoNgasAEKSy%2FEC3PU5PpgkmdANakYHgTOJ%2BWXz78A3se5qwbDJdM5SFyj91vLIqEZoj2RsHYEJKxewVEJmFR1AApR%2FHANN9zJup38DdRoXlk%2BFOWDGWcpmeWNQRvIv%2FLX0X2ANpT9DPDKJAyGmrv0HACTELMAkGBSsOAwIaBQAwgZMGCSqGSIb3DQEHATAUBggqhkiG9w0DBwQIpZJ7oW%2BmbAeAcCqBOg51Ql5tkt0VUyEW76Hmm6BRTYsqqnCHmO5jig6SwNso9yyqfxSG1Wpg0LU0ZGyW8wVcwiIDkGzqtfTf98QCICDJHdOy0PexRc2CDiLLArKwwfMXbMn%2BVEm4nJ2QM1jWVdzfWCtEu5W4oZLBN5qgggOHMIIDgzCCAuygAwIBAgIBADANBgkqhkiG9w0BAQUFADCBjjELMAkGA1UEBhMCVVMxCzAJBgNVBAgTAkNBMRYwFAYDVQQHEw1Nb3VudGFpbiBWaWV3MRQwEgYDVQQKEwtQYXlQYWwgSW5jLjETMBEGA1UECxQKbGl2ZV9jZXJ0czERMA8GA1UEAxQIbGl2ZV9hcGkxHDAaBgkqhkiG9w0BCQEWDXJlQHBheXBhbC5jb20wHhcNMDQwMjEzMTAxMzE1WhcNMzUwMjEzMTAxMzE1WjCBjjELMAkGA1UEBhMCVVMxCzAJBgNVBAgTAkNBMRYwFAYDVQQHEw1Nb3VudGFpbiBWaWV3MRQwEgYDVQQKEwtQYXlQYWwgSW5jLjETMBEGA1UECxQKbGl2ZV9jZXJ0czERMA8GA1UEAxQIbGl2ZV9hcGkxHDAaBgkqhkiG9w0BCQEWDXJlQHBheXBhbC5jb20wgZ8wDQYJKoZIhvcNAQEBBQADgY0AMIGJAoGBAMFHTt38RMxLXJyO2SmS%2BNdl72T7oKJ4u4uw%2B6awntALWh03PewmIJuzbALScsTS4sZoS1fKciBGoh11gIfHzylvkdNe%2FhJl66%2FRGqrj5rFb08sAABNTzDTiqqNpJeBsYs%2Fc2aiGozptX2RlnBktH%2BSUNpAajW724Nv2Wvhif6sFAgMBAAGjge4wgeswHQYDVR0OBBYEFJaffLvGbxe9WT9S1wob7BDWZJRrMIG7BgNVHSMEgbMwgbCAFJaffLvGbxe9WT9S1wob7BDWZJRroYGUpIGRMIGOMQswCQYDVQQGEwJVUzELMAkGA1UECBMCQ0ExFjAUBgNVBAcTDU1vdW50YWluIFZpZXcxFDASBgNVBAoTC1BheVBhbCBJbmMuMRMwEQYDVQQLFApsaXZlX2NlcnRzMREwDwYDVQQDFAhsaXZlX2FwaTEcMBoGCSqGSIb3DQEJARYNcmVAcGF5cGFsLmNvbYIBADAMBgNVHRMEBTADAQH%2FMA0GCSqGSIb3DQEBBQUAA4GBAIFfOlaagFrl71%2Bjq6OKidbWFSE%2BQ4FqROvdgIONth%2B8kSK%2F%2FY%2F4ihuE4Ymvzn5ceE3S%2FiBSQQMjyvb%2Bs2TWbQYDwcp129OPIbD9epdr4tJOUNiSojw7BHwYRiPh58S1xGlFgHFXwrEBb3dgNbMUa%2Bu4qectsMAXpVHnD9wIyfmHMYIBmjCCAZYCAQEwgZQwgY4xCzAJBgNVBAYTAlVTMQswCQYDVQQIEwJDQTEWMBQGA1UEBxMNTW91bnRhaW4gVmlldzEUMBIGA1UEChMLUGF5UGFsIEluYy4xEzARBgNVBAsUCmxpdmVfY2VydHMxETAPBgNVBAMUCGxpdmVfYXBpMRwwGgYJKoZIhvcNAQkBFg1yZUBwYXlwYWwuY29tAgEAMAkGBSsOAwIaBQCgXTAYBgkqhkiG9w0BCQMxCwYJKoZIhvcNAQcBMBwGCSqGSIb3DQEJBTEPFw0xMTEyMTUxMDU4NDVaMCMGCSqGSIb3DQEJBDEWBBSylL3nuYDcfRrejaarqTxjX7bvOzANBgkqhkiG9w0BAQEFAASBgFbyH6ahYdM4lSBGNMDUrpkFVbHUxRoLiVLyJedir5AHr7ro8SQySMxiKUvhrrFg%2FinqyCvt2NDjboNQ9%2FC9tWe7yqpJKsj9eit57KYzGjwbxPs2oxuJb0U0wgAFojCNLXfkIgfsdRP7A18lr2aimjvuihKZfzRh8CVux9ME0jux-----END%20PKCS7-----)


#### Changes: ####
Version 2.2.0 released:

  * support for common anode TM1638 module (QYF-TM1638);

Version 2.1.3 released:

  * added a define TM1638\_COLOR\_NONE for clarity when clearing a single LED ([issue #26](https://code.google.com/p/tm1638-library/issues/detail?id=#26)).

Version 2.1.2 released:

  * corrected setDisplayDigit repeatedly with the dot set to true ([issue #22](https://code.google.com/p/tm1638-library/issues/detail?id=#22));
  * correction on setDisplayToDecNumber bug (thanks to hbx3485) ([issue #24](https://code.google.com/p/tm1638-library/issues/detail?id=#24)).

Version 2.1.1 released:
  * problems on clearDisplay and setupDisplay ([issue #21](https://code.google.com/p/tm1638-library/issues/detail?id=#21)).

Version 2.1.0 released:

  * support for negative decimal numbers ([issue #20](https://code.google.com/p/tm1638-library/issues/detail?id=#20));
  * corrected setDisplayToString dot bug ([issue #19](https://code.google.com/p/tm1638-library/issues/detail?id=#19)).

Version 2.0.1 released:

  * backwards compatibility with previous Arduino IDE - pure virtual functions were not supported ([issue #15](https://code.google.com/p/tm1638-library/issues/detail?id=#15));
  * corrected problem with setLEDs() caused by changes in the previous version ([issue #18](https://code.google.com/p/tm1638-library/issues/detail?id=#18)).

Version 2.0.0 released:

  * support for the TM1640;
  * restructuring for supporting other modules.
    * _WARNING: some restructuring for supporting the TM1640 but code for older versions using the TM1638 shouldn't be affected_

Version 1.6.0 released:
  * support for starting position on setDisplayToString() methods ([issue #10](https://code.google.com/p/tm1638-library/issues/detail?id=#10))
    * _WARNING: setDisplayToString methods have changed prototype and are incompatible with code compiled for 1.5.x (if you specified a custom font)_

Version 1.5.2 released:
  * backwards compatibility with previous Arduino IDE - pre IDE version 1.0 ([issue #9](https://code.google.com/p/tm1638-library/issues/detail?id=#9)).

Version 1.5.1 released:
  * new character data in default font for '`*`' ([issue #7](https://code.google.com/p/tm1638-library/issues/detail?id=#7));
  * minor optimization on inverted TM1638.

Version 1.5.0 released:
  * support for inverted module;
  * support for Arduino IDE 1.0;
  * new functions usage example added;
  * some restructuring.

Version 1.4.0 released:
  * support for specifying dots on setDisplayToString ([issue #6](https://code.google.com/p/tm1638-library/issues/detail?id=#6))
    * _WARNING: setDisplayToString methods have changed prototype and are incompatible with code compiled for 1.3.x (if you specified a custom font)_

Version 1.3.2 released:
  * correction of string library import ([issue #5](https://code.google.com/p/tm1638-library/issues/detail?id=#5)).

Version 1.3.1 released:
  * changed pins on the examples to match schematics on project site.

Version 1.3.0 released:
  * added support for String Object;
  * added support for removing leading zeros in displaying numbers.

Version 1.2.0 released: added support for writing text.


Version 1.1.0: restructuring and added 2 proper examples, available in the arduino ide.

#### Example schematics ####

[Example schematic for one module](http://tm1638-library.googlecode.com/files/tm1638%20-%20one%20module_schem.svg)

[Example schematic](http://tm1638-library.googlecode.com/files/tm1638_schem.svg)

![http://tm1638-library.googlecode.com/files/tm1638helper.png](http://tm1638-library.googlecode.com/files/tm1638helper.png)
![http://tm1638-library.googlecode.com/files/tm1638%20-%20one%20module_schem.png](http://tm1638-library.googlecode.com/files/tm1638%20-%20one%20module_schem.png)
![http://tm1638-library.googlecode.com/files/tm1638_schem.png](http://tm1638-library.googlecode.com/files/tm1638_schem.png)