#include "Controller.h"

Controller::Controller() : v(new View()) {}

void Controller::init(int argc, char *argv[])
{
    ifstream file1;
    string line, s1, s2, s3, s4, s5;
    for (size_t i = 1; i < argc; i++)
    {
        file1.open(argv[i]);
        s1 = (argv[i]);
        if (s1.find("castle") != string::npos)
        {
            //cout << "castle file found" << endl;
            while (getline(file1, line))
            {
                replace(line.begin(), line.end(), ',', ' ');
                replace(line.begin(), line.end(), '(', ' ');
                replace(line.begin(), line.end(), ')', ' ');
                stringstream ss(line);
                ss >> s1 >> s2 >> s3 >> s4;
                Model::getInstance().addStructure(new Castle(s1, Point(stoi(s2), stoi(s3)), stoi(s4)));
            }
            file1.close();
        }
        if (s1.find("farm") != string::npos)
        {
            while (getline(file1, line))
            {
                replace(line.begin(), line.end(), ',', ' ');
                replace(line.begin(), line.end(), '(', ' ');
                replace(line.begin(), line.end(), ')', ' ');
                stringstream ss(line);
                ss >> s1 >> s2 >> s3 >> s4 >> s5;
                Model::getInstance().addStructure(new Farm(s1, Point(stoi(s2), stoi(s3)), stoi(s4), stoi(s5)));
            }
            file1.close();
        }
    }
}

void Controller::attach()
{
    v->setObjects(Model::getInstance().getAllList());
}
void Controller::control()
{
    string input, input2, input3;
    int num;
    float sc, x1, y1, x2, y2;
    Agent *at;
    Structure *st;
    Point p;
    do
    {
        cout << "Time " << Model::getInstance().time << ": ";
        cin >> input;
        if (input == "default")
        {
            v->setSize(25);
            v->setScale(2);
            p = Point();
            v->setOrigin(p);
        }
        else if (input == "show")
        {
            attach();
            v->draw();
        }
        else if (input == "size")
        {
            cin >> num;
            v->setSize(num);
        }
        else if (input == "zoom")
        {
            cin >> num;
            v->setScale(num);
        }
        else if (input == "pan")
        {
            cin >> x1 >> y1;
            Point p = Point(x1, y1);
            v->setOrigin(p);
        }
        else if (input == "create")
        {
            cin >> input >> input2;
            if (Model::getInstance().findAgent(input))
            {
                cout << "Error ! an agent by this name already exist !" << endl;
                continue;
            }
            if (input2 == "Peasant")
            {
                cin >> input3 >> input2;
                replace(input3.begin(), input3.end(), ',', ' ');
                replace(input3.begin(), input3.end(), '(', ' ');
                replace(input2.begin(), input2.end(), ')', ' ');
                Model::getInstance().addAgent(new Peasant(input, Point(stoi(input3), stoi(input2))));
            }
            else if (input2 == "Knight")
            {
                cin >> input3;
                Model::getInstance().addAgent(new Knight(input, Model::getInstance().findStructure(input3)->getLoc()));
            }
        }
        else if (input == "go")
        {
            Model::getInstance().update();
        }
        else if ((at = Model::getInstance().getAgent(input)) != nullptr)
        {
            if(at->getSign() == 'P'){
                cin >> input2;
                if (input2 == "start_working")
                {
                    cin >> input2 >> input3;
                    Model::getInstance().setPeasantWork(input, input2, input3);
                    cout << input << " is going to work, from " << input2 << " to " << input3 << endl;
                }
            }
            else if(at->getSign() == 'K'){
                cin >> input2;
                if (input2 == "destination")
                {
                    cin >> input3;
                    if ((st = Model::getInstance().findStructure(input3)) != nullptr)
                    {
                        at->setDest(st);
                        cout << input << " is heading to " << input3 << " on patrol" << endl;
                    }
                }
                else if (input2 == "course"){
                    cin >> x1;
                    at->setCourse(x1);
                }

                else if(input2 == "position"){
                    cin >> x1 >> x2;
                    Point p = Point(x1,x2);
                    at->setPos(p);
                }

                // else if(input2 == "position")
            }


            else if (input2 == "status")
            {
                at->print();
            }
            else if (input2 == "stop")
            {
                at->stop();
            }
        }
        else if (input != "exit")
        {
            cerr << "ERROR! wrong input!" << endl;
        }

    } while (input != "exit");
}

void Controller::run()
{
    // Model::getInstance().addStructure(new Farm("Manor_Farm", Point(0, 0), 4));
    // Model::getInstance().addStructure(new Farm("Animal_Farm", Point(49, 49), 9));
    // Model::getInstance().addStructure(new Farm("Foxwood_Farm", Point(0, 49), 2));
    // Model::getInstance().addStructure(new Farm("Pinchfield_Farm", Point(49, 0), 3));
    // Model::getInstance().addStructure(new Castle("White_Castle", Point(25, 25)));
    // Model::getInstance().addAgent(new Peasant("Gorge"));
    // Model::getInstance().addAgent(new Peasant("John"));
    // Model::getInstance().addAgent(new Peasant("Paul"));
    // Model::getInstance().addAgent(new Peasant("Ringo"));
    // Model::getInstance().setPeasantWork("Gorge", "Manor_Farm", "White_Castle");
    // Model::getInstance().setPeasantWork("John", "Animal_Farm", "White_Castle");
    // Model::getInstance().setPeasantWork("Paul", "Foxwood_Farm", "White_Castle");
    // Model::getInstance().setPeasantWork("Ringo", "Pinchfield_Farm", "White_Castle");
    // attach();
    // v->draw();
    control();
}