Proximity Focusing RICH
=======================

Example for `Geant4OpticalTracker` SD plugin usage

## Local Development
The following assumes that your working directory is `pwd` (`DD4hep/examples/OpticalTracker`).

Local build:
```bash
cmake -B build -S . -D CMAKE_INSTALL_PREFIX=install
cmake --build build -- install
```

View the geometry (using `dd_web_display`, currently a tool from [NPDet](https://eicweb.phy.anl.gov/EIC/NPDet));
this will produce `geo.root`, which contains the `TGeo` geometry and can be browsed with [JSroot](https://root.cern/js/):
```bash
scripts/view.sh
```

Run a test simulation:
```bash
scripts/run_richsim.sh
```

### TODO
- documentation (`npsim`, `Geant4OpticalTracker`, etc.)
- remove unnecessary materials, colors, etc.
- add tests (to `CMakeLists.txt`)
