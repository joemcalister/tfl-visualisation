# Traffic visualisation using TfL data
![Traffic Visualisation](https://joemcalister.com/img/git/traffic-vis.jpg)
This project is a visual representation of the road incidents that occur in the past 24 hours in London, using data from TfL and openFrameworks.

## How to install
This is a Xcode open frameworks project so in order to compile/build it you need to place the ```traffic-visualisation``` folder inside a folder named ```PAP``` within the openframeworks apps directory. The path should be equivalent to ```(openFrameworks folder) > apps > PAP > traffic-visulisation```
The following addons are also required:
*[ofxParagraph](https://github.com/braitsch/ofxParagraph)
*[ofxSmartFont](https://github.com/braitsch/ofxSmartFont)
*[ofxXmlSettings](http://openframeworks.cc/documentation/ofxXmlSettings/ofxXmlSettings/)

## How to compile
Once in the correct location (see above) you can use the makefile.
```Shell
make
```