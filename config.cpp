class CfgPatches
{
      class W_RGR_MOD
      {
            units[] = {"174_Rgr_TeamLeader"}; //Array of custom units    
      };
};
     
class CfgFactionClasses //Configure faction details
{
      class 174_US_RGR //Unique faction class
      {
            displayName = "US Army Rangers"; //Faction name in-game
            Priority = 6; //Priority in menus
            side = 1; //0 = Opfor, 1 = Blufor, 2 = Independent, 3 = Civillian
      };
};
     
class CfgVehicleClasses
{
      class 174_US_RGR_MEN //Unique vehicle class
      {
            displayName = "Men"; //Unit type name in-game (Men, Armor, etc.)
            priority = 1; //Priority in menus
            };
      };

class CfgVehicles //Used for defining any vehicle/unit
{
      class B_Soldier_F; //Predefining inheritence class
     
      class 174_Rgr_TeamLeader : B_Soldier_F //New unit classname : Inheritence class
      {
            author = "JaithWraith"; //Self explanatory
            side = 1; //0 = Opfor, 1 = Blufor, 2 = Independent, 3 = Civillian
            faction = "174_US_RGR"; //Custom faction class from above
            _generalMacro = "B_Soldier_F"; //Add and include inheritence class for Zeus compatability
            vehicleclass = "174_US_RGR_MEN"; //Custom vehicle class from above
            scope = 2; //0 = Invisible, 1 = Invisible but usable, 2 = Visible and usable
            displayName = "Ranger Team Leader";
            editorCatergory = "174_US_RGR"; //Must match unique faction class from above
            //editorSubCatergory = "Custom_xx"; //Leave commented out unless you want to specify otherwise
            backpack = "B_AssaultPack_rgr"; //Self explanatory .. comment out if you don't want a backpack/to inherit from class
            weapons[] = {"arifle_SPAR_01_GL_blk_F", "hgun_P07_F","Throw","Put"}; //Weapons the unit should spawn with
            respawnWeapons[] = {"arifle_SPAR_01_GL_blk_F", "hgun_P07_F","Throw","Put"}; //Should be same as above
            magazines[] = {"HandGrenade","GandGrenade","SmokeShell","SmokeShell","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_Smoke_Grenade_shell"}; //Initial mag loadout
            respawnMagazines[] = {"HandGrenade","GandGrenade","SmokeShell","SmokeShell","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_Smoke_Grenade_shell"}; //Should be same as above
            linkedItems[] = {"V_PlateCarrier1_rgr","H_HelmetB_light_sand","Rangefinder","ItemMap","ItemCompass","ItemWatch","ItemRadio","NVGogglesB_grn_F"}; //Initial vest, helmet, and misc. gear
            respawnLinkedItems[] = {"V_PlateCarrier1_rgr","H_HelmetB_light_sand","Rangefinder","ItemMap","ItemCompass","ItemWatch","ItemRadio","NVGogglesB_grn_F"}; //Should be same as above
            uniformClass = "U_B_CombatUniform_mcam"; //Uniform to equip
            //hiddenSelections[] = {"camo"}; //ONLY COMMENT THESE IN IF YOU ARE RETEXTURING. IF OTHERWISE IT WILL INHERIT THE UNIFORM FROM THE INHERITANCE CLASS
            //HiddenSelectionsTextures[] = {"TEST\data\TEST_Uniform_co.paa"};    //Uniform textures path must be to your .pbo
      };
};
              
