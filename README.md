# TankWars
A simple, tank battleground game built using Unreal Engine

To Open the project on your PC you will need to add the starter pack manually and rebuild some of the derived files

************************************************************************************************************
UP UNTIL THE COMMIT TITLED "WORKING AROUND BUG" THE TURRET STATIC MESH WOULD DISAPPEAR UPON REOPENING UE4 OR MAKING ANY CHANGES TO THE TANK.CPP FILE. WORKED AROUND BY SETTING THE STATIC MESH EVERY TIME ON BeginPlay THROUGH TANK_BLUEPRINT.

IF YOU WANT TO MAKE THE OLDER VERSIONS VISIBLE AS WELL, GO TO TANK'S BLUEPRINT AND ADD STATIC MESH NAMED "tank_fbx_Turret"
