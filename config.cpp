#define mag_xx(a,b) class _xx_##a {magazine = a; count = b;} //Equipment list macros used below
#define weap_xx(a,b) class _xx_##a {weapon = a; count = b;}
#define item_xx(a,b) class _xx_##a {name = a; count = b;}

class CfgPatches
{
      class JW_RGR_MOD
      {
            units[] = {"jw_bkpk_stnd","jw_bkpk_med","jw_Rgr_TeamLeader","jw_Rgr_Grenadier","jw_Rgr_Autorifleman","jw_Rgr_Medic"}; //Array of custom units    
      };
};
     
class CfgFactionClasses //Configure faction details
{
      class JW_US_RGR //Unique faction class
      {
            displayName = "US Army Rangers"; //Faction name in-game
            Priority = 6; //Priority in menus
            side = 1; //0 = Opfor, 1 = Blufor, 2 = Independent, 3 = Civillian
      };
};
     
class CfgVehicleClasses
{
      class JW_US_RGR_MEN //Unique vehicle class
      {
            displayName = "Men"; //Unit type name in-game (Men, Armor, etc.)
            priority = 1; //Priority in menus
      };
};

class CfgVehicles //Used for defining any vehicle/unit
{
      class B_AssaultPack_rgr; //standard backpack configuration

      class jw_bkpk_stnd: B_AssaultPack_rgr
      {
            author = "JaithWraith";
            scope = 1;
            class TransportItems
            {
                  item_xx(ACE_fieldDressing,12);
                  item_xx(ACE_morphine,5);
                  item_xx(ACE_epinephrine,2);
                  item_xx(ACE_bloodIV_250,2);
            };
      };
      
      class B_KitBag_rgr; //medic kitbag configuration

      class jw_bkpk_med: B_AssaultPack_rgr
      {
            author = "JaithWraith";
            scope = 1;
            class TransportItems
            {
                  item_xx(ACE_fieldDressing,40);
                  item_xx(ACE_morphine,15);
                  item_xx(ACE_epinephrine,6);
                  item_xx(ACE_bloodIV_250,4);
                  item_xx(ACE_bloodIV_500,4);
                  item_xx(ACE_bloodIV,4);
            };
      };
      
      class B_Recon_TL_F; //Predefining inheritence class
     
      class jw_Rgr_TeamLeader : B_Recon_TL_F //New unit classname : Inheritence class
      {
            author = "JaithWraith"; //Self explanatory
            side = 1; //0 = Opfor, 1 = Blufor, 2 = Independent, 3 = Civillian
            faction = "JW_US_RGR"; //Custom faction class from above
            _generalMacro = "B_Recon_TL_F"; //Add and include inheritence class for Zeus compatability
            vehicleclass = "JW_US_RGR_MEN"; //Custom vehicle class from above
            scope = 2; //0 = Invisible, 1 = Invisible but usable, 2 = Visible and usable
            displayName = "Ranger Team Leader";
            editorCatergory = "JW_US_RGR"; //Must match unique faction class from above
            //editorSubCatergory = "Custom_xx"; //Leave commented out unless you want to specify otherwise
            backpack = "jw_bkpk_stnd"; //Self explanatory .. comment out if you don't want a backpack/to inherit from class
            weapons[] = {"arifle_SPAR_01_GL_blk_F","hgun_P07_F","ACE_Vector","Throw","Put"}; //Weapons the unit should spawn with
            respawnWeapons[] = {"arifle_SPAR_01_GL_blk_F","hgun_P07_F","ACE_Vector","Throw","Put"}; //Should be same as above
            magazines[] = {"HandGrenade","HandGrenade","SmokeShell","SmokeShell","SmokeShell","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_Smoke_Grenade_shell"}; //Initial mag loadout
            respawnMagazines[] = {"HandGrenade","HandGrenade","SmokeShell","SmokeShell","SmokeShell","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_Smoke_Grenade_shell"}; //Should be same as above
            linkedItems[] = {"V_PlateCarrier1_rgr","H_HelmetB_light_sand","ItemMap","ItemCompass","ItemWatch","ItemRadio","NVGogglesB_grn_F"}; //Initial vest, helmet, and misc. gear
            respawnLinkedItems[] = {"V_PlateCarrier1_rgr","H_HelmetB_light_sand","ItemMap","ItemCompass","ItemWatch","ItemRadio","NVGogglesB_grn_F"}; //Should be same as above
            uniformClass = "U_B_CombatUniform_mcam"; //Uniform to equip
            //hiddenSelections[] = {"camo"}; //ONLY COMMENT THESE IN IF YOU ARE RETEXTURING. IF OTHERWISE IT WILL INHERIT THE UNIFORM FROM THE INHERITANCE CLASS
            //HiddenSelectionsTextures[] = {"TEST\data\TEST_Uniform_co.paa"};    //Uniform textures path must be to your .pbo
      };
      
      class B_Recon_JTAC_F; //Predefining inheritence class
     
      class jw_Rgr_Grenadier : B_Recon_JTAC_F //New unit classname : Inheritence class
      {
            author = "JaithWraith"; //Self explanatory
            side = 1; //0 = Opfor, 1 = Blufor, 2 = Independent, 3 = Civillian
            faction = "JW_US_RGR"; //Custom faction class from above
            _generalMacro = "B_Recon_JTAC_F"; //Add and include inheritence class for Zeus compatability
            vehicleclass = "JW_US_RGR_MEN"; //Custom vehicle class from above
            scope = 2; //0 = Invisible, 1 = Invisible but usable, 2 = Visible and usable
            displayName = "Ranger Grenadier";
            editorCatergory = "JW_US_RGR"; //Must match unique faction class from above
            //editorSubCatergory = "Custom_xx"; //Leave commented out unless you want to specify otherwise
            backpack = "jw_bkpk_stnd"; //Self explanatory .. comment out if you don't want a backpack/to inherit from class
            weapons[] = {"arifle_SPAR_01_GL_blk_F","hgun_P07_F","Throw","Put"}; //Weapons the unit should spawn with
            respawnWeapons[] = {"arifle_SPAR_01_GL_blk_F","hgun_P07_F","Throw","Put"}; //Should be same as above
            magazines[] = {"HandGrenade","HandGrenade","SmokeShell","SmokeShell","SmokeShell","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_Smoke_Grenade_shell"}; //Initial mag loadout
            respawnMagazines[] = {"HandGrenade","HandGrenade","SmokeShell","SmokeShell","SmokeShell","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_Smoke_Grenade_shell"}; //Should be same as above
            linkedItems[] = {"V_PlateCarrier1_rgr","H_HelmetB_light_sand","ItemMap","ItemCompass","ItemWatch","ItemRadio","NVGogglesB_grn_F"}; //Initial vest, helmet, and misc. gear
            respawnLinkedItems[] = {"V_PlateCarrier1_rgr","H_HelmetB_light_sand","ItemMap","ItemCompass","ItemWatch","ItemRadio","NVGogglesB_grn_F"}; //Should be same as above
            uniformClass = "U_B_CombatUniform_mcam"; //Uniform to equip
            //hiddenSelections[] = {"camo"}; //ONLY COMMENT THESE IN IF YOU ARE RETEXTURING. IF OTHERWISE IT WILL INHERIT THE UNIFORM FROM THE INHERITANCE CLASS
            //HiddenSelectionsTextures[] = {"TEST\data\TEST_Uniform_co.paa"};    //Uniform textures path must be to your .pbo
      };
      
      class B_Recon_JTAC_F; //Predefining inheritence class
     
      class jw_Rgr_Autorifleman : B_Recon_JTAC_F //New unit classname : Inheritence class
      {
            author = "JaithWraith"; //Self explanatory
            side = 1; //0 = Opfor, 1 = Blufor, 2 = Independent, 3 = Civillian
            faction = "JW_US_RGR"; //Custom faction class from above
            _generalMacro = "B_Recon_JTAC_F"; //Add and include inheritence class for Zeus compatability
            vehicleclass = "JW_US_RGR_MEN"; //Custom vehicle class from above
            scope = 2; //0 = Invisible, 1 = Invisible but usable, 2 = Visible and usable
            displayName = "Ranger Autorifleman";
            editorCatergory = "JW_US_RGR"; //Must match unique faction class from above
            //editorSubCatergory = "Custom_xx"; //Leave commented out unless you want to specify otherwise
            backpack = "jw_bkpk_stnd"; //Self explanatory .. comment out if you don't want a backpack/to inherit from class
            weapons[] = {"arifle_SPAR_02_blk_F","hgun_P07_F","Throw","Put"}; //Weapons the unit should spawn with
            respawnWeapons[] = {"arifle_SPAR_02_blk_F","hgun_P07_F","Throw","Put"}; //Should be same as above
            magazines[] = {"HandGrenade","HandGrenade","SmokeShell","SmokeShell","SmokeShell","150Rnd_556x45_Drum_Mag_F","150Rnd_556x45_Drum_Mag_F","150Rnd_556x45_Drum_Mag_F","150Rnd_556x45_Drum_Mag_F","150Rnd_556x45_Drum_Mag_F","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag"}; //Initial mag loadout
            respawnMagazines[] = {"HandGrenade","HandGrenade","SmokeShell","SmokeShell","SmokeShell","150Rnd_556x45_Drum_Mag_F","150Rnd_556x45_Drum_Mag_F","150Rnd_556x45_Drum_Mag_F","150Rnd_556x45_Drum_Mag_F","150Rnd_556x45_Drum_Mag_F","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag"}; //Should be same as above
            linkedItems[] = {"V_PlateCarrier1_rgr","H_HelmetB_light_sand","ItemMap","ItemCompass","ItemWatch","ItemRadio","NVGogglesB_grn_F"}; //Initial vest, helmet, and misc. gear
            respawnLinkedItems[] = {"V_PlateCarrier1_rgr","H_HelmetB_light_sand","ItemMap","ItemCompass","ItemWatch","ItemRadio","NVGogglesB_grn_F"}; //Should be same as above
            uniformClass = "U_B_CombatUniform_mcam"; //Uniform to equip
            //hiddenSelections[] = {"camo"}; //ONLY COMMENT THESE IN IF YOU ARE RETEXTURING. IF OTHERWISE IT WILL INHERIT THE UNIFORM FROM THE INHERITANCE CLASS
            //HiddenSelectionsTextures[] = {"TEST\data\TEST_Uniform_co.paa"};    //Uniform textures path must be to your .pbo
      };
      
      class B_recon_medic_F; //Predefining inheritence class
     
      class jw_Rgr_Medic : B_recon_medic_F //New unit classname : Inheritence class
      {
            author = "JaithWraith"; //Self explanatory
            side = 1; //0 = Opfor, 1 = Blufor, 2 = Independent, 3 = Civillian
            faction = "JW_US_RGR"; //Custom faction class from above
            _generalMacro = "B_recon_medic_F"; //Add and include inheritence class for Zeus compatability
            vehicleclass = "JW_US_RGR_MEN"; //Custom vehicle class from above
            scope = 2; //0 = Invisible, 1 = Invisible but usable, 2 = Visible and usable
            displayName = "Ranger Medic";
            editorCatergory = "JW_US_RGR"; //Must match unique faction class from above
            //editorSubCatergory = "Custom_xx"; //Leave commented out unless you want to specify otherwise
            backpack = "jw_bkpk_med"; //Self explanatory .. comment out if you don't want a backpack/to inherit from class
            weapons[] = {"arifle_SPAR_01_blk_F","hgun_P07_F","Throw","Put"}; //Weapons the unit should spawn with
            respawnWeapons[] = {"arifle_SPAR_01_blk_F","hgun_P07_F","Throw","Put"}; //Should be same as above
            magazines[] = {"HandGrenade","HandGrenade","SmokeShell","SmokeShell","SmokeShell","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag"}; //Initial mag loadout
            respawnMagazines[] = {"HandGrenade","HandGrenade","SmokeShell","SmokeShell","SmokeShell","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag"}; //Should be same as above
            linkedItems[] = {"V_PlateCarrier1_rgr","H_HelmetB_light_sand","ItemMap","ItemCompass","ItemWatch","ItemRadio","NVGogglesB_grn_F"}; //Initial vest, helmet, and misc. gear
            respawnLinkedItems[] = {"V_PlateCarrier1_rgr","H_HelmetB_light_sand","ItemMap","ItemCompass","ItemWatch","ItemRadio","NVGogglesB_grn_F"}; //Should be same as above
            uniformClass = "U_B_CombatUniform_mcam"; //Uniform to equip
            //hiddenSelections[] = {"camo"}; //ONLY COMMENT THESE IN IF YOU ARE RETEXTURING. IF OTHERWISE IT WILL INHERIT THE UNIFORM FROM THE INHERITANCE CLASS
            //HiddenSelectionsTextures[] = {"TEST\data\TEST_Uniform_co.paa"};    //Uniform textures path must be to your .pbo
      };
};
              
