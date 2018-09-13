#include <G3D\G3D.h>

int generateStaircase() {
    TextOutput file(String("D:\\programs\\graphics-projects\\cubes\\data-files\\scene\\staircase.Scene.Any"));

    file.writeSymbol("// -*- c++ -*-");
    file.writeNewline(); file.writeNewline();
    file.writeSymbol("{ name = \"Stairwell\";");
    file.writeNewline(); file.writeNewline();
    file.writeSymbol(
    "models = {\
        stepModel = ArticulatedModel::Specification{\
            filename = \"model/crate/crate.obj\";\
            preprocess = {\
                setMaterial(all(), \"model/crate/woodcrate-L.png\");\
                moveCenterToOrigin();\
                transformGeometry(all(), Matrix4::scale(0.3, 0.075, 1.25));\
            };\
        };\
    };\
    \
    entities = {\
        skybox = Skybox{\
            texture = \"cubemap/whiteroom/whiteroom-*.png\";\
        };\
    \
        sun = Light{\
            attenuation = (0, 0, 1);\
            bulbPower = Power3(1e+006);\
            frame = CFrame::fromXYZYPRDegrees(0, 1.02, 0, 0, 0, 0);\
            shadowMapSize = Vector2int16(2048, 2048);\
            spotHalfAngleDegrees = 5;\
            rectangular = true;\
            type = \"SPOT\";\
        };");
    file.writeNewline();

    double height = 0;
    int yaw = 0;
    String stepNum;
    String heightNum;
    String yawNum;
    for (int i = 0; i < 50; ++i) {
        stepNum = String(std::to_string(i));
        heightNum = String(std::to_string(height));
        yawNum = String(std::to_string(yaw));
        file.writeSymbol(
            "step" + stepNum + " = VisibleEntity{\
            model = \"stepModel\";\
            frame = CFrame::fromXYZYPRDegrees(0, " + heightNum + ", 0, " + yawNum + ", 0, 0);\
            };");
        height += 0.075;
        yaw += 15;
    }

    file.writeNewline();
    file.writeSymbol(
        "camera = Camera{\
            frame = CFrame::fromXYZYPRDegrees(0, 0, 5);\
        };\
    };\
    };");
    file.writeNewline();

    file.commit();

    return 0;
}
