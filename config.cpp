#define mag_xx(a,b) class _xx_##a {magazine = a; count = b;} //Equipment list macros used below
#define weap_xx(a,b) class _xx_##a {weapon = a; count = b;}
#define item_xx(a,b) class _xx_##a {name = a; count = b;}

class CfgPatches
{
      class JW_RGR_MOD
      {
            weapons[] = {"jw_rgr_uniform_mcam"}; //Array of custom weapons
            units[] = {"jw_bkpk_stnd","jw_bkpk_med","jw_bkpk_combeng","jw_bkpk_rad","jw_Rgr_TeamLeader","jw_Rgr_Medic","jw_Rgr_Infantryman","jw_Rgr_CombEng","jw_Rgr_RadioOM"}; //Array of custom units    
      };
};
     
class cfgWeapons
{
      class U_B_CombatUniform_mcam; //ranger uniform configuration
 
      class jw_rgr_uniform_mcam: U_B_CombatUniform_mcam
      {
            author = "JaithWraith";
            scope = 1;
            class TransportItems
            {
                  item_xx(ACE_CableTie,3);
                  item_xx(ACE_Flashlight_XL50,1);
                  item_xx(ACE_EarPlugs,2);
                  item_xx(ACE_MapTools,1);
                  item_xx(ACE_IT_Strobe_Item,1);
            };

            class TransportMagazines
            {
                  mag_xx(HandGrenade,2);
                  mag_xx(SmokeShell,2);
                  mag_xx(ACE_M84,1);
            };
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
                  item_xx(ACE_fieldDressing,20);
                  item_xx(ACE_morphine,8);
                  item_xx(ACE_epinephrine,2);
                  item_xx(ACE_bloodIV_250,2);
            };
      };
      
      class B_AssaultPack_rgr; //medic assault pack configuration

      class jw_bkpk_med: B_AssaultPack_rgr
      {
            author = "JaithWraith";
            scope = 1;
            class TransportItems
            {
                  item_xx(ACE_fieldDressing,40);
                  item_xx(ACE_morphine,20);
                  item_xx(ACE_epinephrine,8);
                  item_xx(ACE_bloodIV_250,4);
                  item_xx(ACE_bloodIV_500,4);
                  item_xx(ACE_bloodIV,4);
            };
      };
      
      class B_Kitbag_rgr; //combat engineer assault pack configuration

      class jw_bkpk_combeng: B_Kitbag_rgr
      {
            author = "JaithWraith";
            scope = 1;
            class TransportItems
            {
                  item_xx(ACE_fieldDressing,20);
                  item_xx(ACE_morphine,8);
                  item_xx(ACE_epinephrine,2);
                  item_xx(ACE_bloodIV_250,2);
            };
            
            class TransportMagazines
            {
                  mag_xx(DemoCharge_Remote_Mag,2);
                  mag_xx(ClaymoreDirectionalMine_Remote_Mag,1);
            };
      };
      
      class tf_anprc155_coyote; //radio operator-maintainer pack configuration
      
      class jw_bkpk_rad: tf_anprc155_coyote
      {
            author = "JaithWraith";
            scope = 1;
            class TransportItems
            {
                  item_xx(ACE_fieldDressing,20);
                  item_xx(ACE_morphine,8);
                  item_xx(ACE_epinephrine,2);
                  item_xx(ACE_bloodIV_250,2);
            };
      };
      
      class B_recon_TL_F; //Predefining inheritence class
     
      class jw_Rgr_TeamLeader : B_recon_TL_F //New unit classname : Inheritence class
      {
            author = "JaithWraith"; //Self explanatory
            side = 1; //0 = Opfor, 1 = Blufor, 2 = Independent, 3 = Civillian
            faction = "JW_US_RGR"; //Custom faction class from above
            _generalMacro = "B_recon_TL_F"; //Add and include inheritence class for Zeus compatability
            vehicleclass = "JW_US_RGR_MEN"; //Custom vehicle class from above
            scope = 2; //0 = Invisible, 1 = Invisible but usable, 2 = Visible and usable
            displayName = "Ranger Infantry Team Leader";
            editorCatergory = "JW_US_RGR"; //Must match unique faction class from above
            //editorSubCatergory = "Custom_xx"; //Leave commented out unless you want to specify otherwise
            backpack = "jw_bkpk_stnd"; //Self explanatory .. comment out if you don't want a backpack/to inherit from class
            weapons[] = {"arifle_SPAR_01_GL_blk_ERCO_Pointer_F","hgun_P07_F","ACE_Vector","Throw","Put"}; //Weapons the unit should spawn with
            respawnWeapons[] = {"arifle_SPAR_01_GL_blk_ERCO_Pointer_F","hgun_P07_F","ACE_Vector","Throw","Put"}; //Should be same as above
            magazines[] = {"HandGrenade","HandGrenade","SmokeShell","SmokeShell","ACE_M84","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_Smoke_Grenade_shell"}; //Initial mag loadout
            respawnMagazines[] = {"HandGrenade","HandGrenade","SmokeShell","SmokeShell","ACE_M84","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_Smoke_Grenade_shell"}; //Should be same as above
            items[] = {"ACE_IR_Strobe_Item","ACE_CableTie","ACE_CableTie","ACE_CableTie","ACE_Flashlight_XL50","ACE_EarPlugs","ACE_MapTools"}; //Initial items
            respawnItems[] = {"ACE_IR_Strobe_Item","ACE_CableTie","ACE_CableTie","ACE_CableTie","ACE_Flashlight_XL50","ACE_EarPlugs","ACE_MapTools"}; //Should be the same as above
            linkedItems[] = {"V_PlateCarrier1_rgr","H_HelmetB_light_sand","ItemMap","ItemGPS","ItemCompass","ItemWatch","tf_anprc152","NVGogglesB_grn_F"}; //Initial vest, helmet, and misc. gear
            respawnLinkedItems[] = {"V_PlateCarrier1_rgr","H_HelmetB_light_sand","ItemMap","ItemCompass","ItemWatch","tf_anprc152","NVGogglesB_grn_F"}; //Should be same as above
            uniformClass = "jw_rgr_uniform_mcam"; //Uniform to equip
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
            displayName = "Ranger Combat Medic Specialist";
            editorCatergory = "JW_US_RGR"; //Must match unique faction class from above
            //editorSubCatergory = "Custom_xx"; //Leave commented out unless you want to specify otherwise
            backpack = "jw_bkpk_med"; //Self explanatory .. comment out if you don't want a backpack/to inherit from class
            weapons[] = {"arifle_SPAR_01_blk_ERCO_Pointer_F","hgun_P07_F","Throw","Put"}; //Weapons the unit should spawn with
            respawnWeapons[] = {"arifle_SPAR_01_blk_ERCO_Pointer_F","hgun_P07_F","Throw","Put"}; //Should be same as above
            magazines[] = {"HandGrenade","HandGrenade","SmokeShell","SmokeShell","ACE_M84","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag"}; //Initial mag loadout
            respawnMagazines[] = {"HandGrenade","HandGrenade","SmokeShell","SmokeShell","ACE_M84","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag"}; //Should be same as above
            items[] = {"ACE_IR_Strobe_Item","ACE_CableTie","ACE_CableTie","ACE_CableTie","ACE_Flashlight_XL50","ACE_EarPlugs","ACE_MapTools"}; //Initial items - empty set .. items moved to uniform
            respawnItems[] = {"ACE_IR_Strobe_Item","ACE_CableTie","ACE_CableTie","ACE_CableTie","ACE_Flashlight_XL50","ACE_EarPlugs","ACE_MapTools"}; //Should be the same as above - empty set .. items moved to uniform
            linkedItems[] = {"V_PlateCarrier1_rgr","H_HelmetB_light_sand","ItemMap","ItemGPS","ItemCompass","ItemWatch","tf_anprc152","NVGogglesB_grn_F"}; //Initial vest, helmet, and misc. gear
            respawnLinkedItems[] = {"V_PlateCarrier1_rgr","H_HelmetB_light_sand","ItemMap","ItemCompass","ItemWatch","tf_anprc152","NVGogglesB_grn_F"}; //Should be same as above
            uniformClass = "jw_rgr_uniform_mcam"; //Uniform to equip
            //hiddenSelections[] = {"camo"}; //ONLY COMMENT THESE IN IF YOU ARE RETEXTURING. IF OTHERWISE IT WILL INHERIT THE UNIFORM FROM THE INHERITANCE CLASS
            //HiddenSelectionsTextures[] = {"TEST\data\TEST_Uniform_co.paa"};    //Uniform textures path must be to your .pbo
      };
      
      class B_recon_F; //Predefining inheritence class
     
      class jw_Rgr_Infantryman : B_recon_F //New unit classname : Inheritence class
      {
            author = "JaithWraith"; //Self explanatory
            side = 1; //0 = Opfor, 1 = Blufor, 2 = Independent, 3 = Civillian
            faction = "JW_US_RGR"; //Custom faction class from above
            _generalMacro = "B_recon_F"; //Add and include inheritence class for Zeus compatability
            vehicleclass = "JW_US_RGR_MEN"; //Custom vehicle class from above
            scope = 2; //0 = Invisible, 1 = Invisible but usable, 2 = Visible and usable
            displayName = "Ranger Infantryman";
            editorCatergory = "JW_US_RGR"; //Must match unique faction class from above
            //editorSubCatergory = "Custom_xx"; //Leave commented out unless you want to specify otherwise
            backpack = "jw_bkpk_stnd"; //Self explanatory .. comment out if you don't want a backpack/to inherit from class
            weapons[] = {"arifle_SPAR_01_blk_ERCO_Pointer_F","hgun_P07_F","Throw","Put"}; //Weapons the unit should spawn with
            respawnWeapons[] = {"arifle_SPAR_01_blk_ERCO_Pointer_F","hgun_P07_F","Throw","Put"}; //Should be same as above
            magazines[] = {"HandGrenade","HandGrenade","SmokeShell","SmokeShell","ACE_M84","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag"}; //Initial mag loadout
            respawnMagazines[] = {"HandGrenade","HandGrenade","SmokeShell","SmokeShell","ACE_M84","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag"}; //Should be same as above
            items[] = {"ACE_IR_Strobe_Item","ACE_CableTie","ACE_CableTie","ACE_CableTie","ACE_Flashlight_XL50","ACE_EarPlugs","ACE_MapTools"}; //Initial items - empty set .. items moved to uniform
            respawnItems[] = {"ACE_IR_Strobe_Item","ACE_CableTie","ACE_CableTie","ACE_CableTie","ACE_Flashlight_XL50","ACE_EarPlugs","ACE_MapTools"}; //Should be the same as above - empty set .. items moved to uniform
            linkedItems[] = {"V_PlateCarrier1_rgr","H_HelmetB_light_sand","ItemMap","ItemGPS","ItemCompass","ItemWatch","tf_anprc152","NVGogglesB_grn_F"}; //Initial vest, helmet, and misc. gear
            respawnLinkedItems[] = {"V_PlateCarrier1_rgr","H_HelmetB_light_sand","ItemMap","ItemCompass","ItemWatch","tf_anprc152","NVGogglesB_grn_F"}; //Should be same as above
            uniformClass = "jw_rgr_uniform_mcam"; //Uniform to equip
            //hiddenSelections[] = {"camo"}; //ONLY COMMENT THESE IN IF YOU ARE RETEXTURING. IF OTHERWISE IT WILL INHERIT THE UNIFORM FROM THE INHERITANCE CLASS
            //HiddenSelectionsTextures[] = {"TEST\data\TEST_Uniform_co.paa"};    //Uniform textures path must be to your .pbo
      };
      
      class B_recon_exp_F; //Predefining inheritence class
      
      class jw_Rgr_CombEng : B_recon_exp_F //New unit classname : Inheritence class
      {
            author = "JaithWraith"; //Self explanatory
            side = 1; //0 = Opfor, 1 = Blufor, 2 = Independent, 3 = Civillian
            faction = "JW_US_RGR"; //Custom faction class from above
            _generalMacro = "B_recon_exp_F"; //Add and include inheritence class for Zeus compatability
            vehicleclass = "JW_US_RGR_MEN"; //Custom vehicle class from above
            scope = 2; //0 = Invisible, 1 = Invisible but usable, 2 = Visible and usable
            displayName = "Ranger Combat Engineer";
            editorCatergory = "JW_US_RGR"; //Must match unique faction class from above
            //editorSubCatergory = "Custom_xx"; //Leave commented out unless you want to specify otherwise
            backpack = "jw_bkpk_combeng"; //Self explanatory .. comment out if you don't want a backpack/to inherit from class
            weapons[] = {"arifle_SPAR_01_blk_ERCO_Pointer_F","hgun_P07_F","Throw","Put"}; //Weapons the unit should spawn with
            respawnWeapons[] = {"arifle_SPAR_01_blk_ERCO_Pointer_F","hgun_P07_F","Throw","Put"}; //Should be same as above
            magazines[] = {"HandGrenade","HandGrenade","SmokeShell","SmokeShell","ACE_M84","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag"}; //Initial mag loadout
            respawnMagazines[] = {"HandGrenade","HandGrenade","SmokeShell","SmokeShell","ACE_M84","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag"}; //Should be same as above
            items[] = {"ACE_IR_Strobe_Item","ACE_CableTie","ACE_CableTie","ACE_CableTie","ACE_Flashlight_XL50","ACE_EarPlugs","ACE_MapTools","ACE_Clacker","ACE_DefusalKit"}; //Initial items
            respawnItems[] = {"ACE_IR_Strobe_Item","ACE_CableTie","ACE_CableTie","ACE_CableTie","ACE_Flashlight_XL50","ACE_EarPlugs","ACE_MapTools","ACE_Clacker","ACE_DefusalKit"}; //Should be the same as above
            linkedItems[] = {"V_PlateCarrier1_rgr","H_HelmetB_light_sand","ItemMap","ItemGPS","ItemCompass","ItemWatch","tf_anprc152","NVGogglesB_grn_F"}; //Initial vest, helmet, and misc. gear
            respawnLinkedItems[] = {"V_PlateCarrier1_rgr","H_HelmetB_light_sand","ItemMap","ItemCompass","ItemWatch","tf_anprc152","NVGogglesB_grn_F"}; //Should be same as above
            uniformClass = "jw_rgr_uniform_mcam"; //Uniform to equip
            //hiddenSelections[] = {"camo"}; //ONLY COMMENT THESE IN IF YOU ARE RETEXTURING. IF OTHERWISE IT WILL INHERIT THE UNIFORM FROM THE INHERITANCE CLASS
            //HiddenSelectionsTextures[] = {"TEST\data\TEST_Uniform_co.paa"};    //Uniform textures path must be to your .pbo
      };
      
      class B_recon_JTAC_F; //Predefining inheritence class
      
      class jw_Rgr_RadioOM : B_recon_JTAC_F //New unit classname : Inheritence class
      {
            author = "JaithWraith"; //Self explanatory
            side = 1; //0 = Opfor, 1 = Blufor, 2 = Independent, 3 = Civillian
            faction = "JW_US_RGR"; //Custom faction class from above
            _generalMacro = "B_recon_JTAC_F"; //Add and include inheritence class for Zeus compatability
            vehicleclass = "JW_US_RGR_MEN"; //Custom vehicle class from above
            scope = 2; //0 = Invisible, 1 = Invisible but usable, 2 = Visible and usable
            displayName = "Ranger Radio Operator-Maintainer";
            editorCatergory = "JW_US_RGR"; //Must match unique faction class from above
            //editorSubCatergory = "Custom_xx"; //Leave commented out unless you want to specify otherwise
            backpack = "jw_bkpk_rad"; //Self explanatory .. comment out if you don't want a backpack/to inherit from class
            weapons[] = {"arifle_SPAR_01_blk_ERCO_Pointer_F","hgun_P07_F","Throw","Put"}; //Weapons the unit should spawn with
            respawnWeapons[] = {"arifle_SPAR_01_blk_ERCO_Pointer_F","hgun_P07_F","Throw","Put"}; //Should be same as above
            magazines[] = {"HandGrenade","HandGrenade","SmokeShell","SmokeShell","ACE_M84","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag"}; //Initial mag loadout
            respawnMagazines[] = {"HandGrenade","HandGrenade","SmokeShell","SmokeShell","ACE_M84","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag"}; //Should be same as above
            items[] = {"ACE_IR_Strobe_Item","ACE_CableTie","ACE_CableTie","ACE_CableTie","ACE_Flashlight_XL50","ACE_EarPlugs","ACE_MapTools"}; //Initial items - empty set .. items moved to uniform
            respawnItems[] = {"ACE_IR_Strobe_Item","ACE_CableTie","ACE_CableTie","ACE_CableTie","ACE_Flashlight_XL50","ACE_EarPlugs","ACE_MapTools"}; //Should be the same as above - empty set .. items moved to uniform
            linkedItems[] = {"V_PlateCarrier1_rgr","H_HelmetB_light_sand","ItemMap","ItemGPS","ItemCompass","ItemWatch","tf_anprc152","NVGogglesB_grn_F"}; //Initial vest, helmet, and misc. gear
            respawnLinkedItems[] = {"V_PlateCarrier1_rgr","H_HelmetB_light_sand","ItemMap","ItemCompass","ItemWatch","tf_anprc152","NVGogglesB_grn_F"}; //Should be same as above
            uniformClass = "jw_rgr_uniform_mcam"; //Uniform to equip
            //hiddenSelections[] = {"camo"}; //ONLY COMMENT THESE IN IF YOU ARE RETEXTURING. IF OTHERWISE IT WILL INHERIT THE UNIFORM FROM THE INHERITANCE CLASS
            //HiddenSelectionsTextures[] = {"TEST\data\TEST_Uniform_co.paa"};    //Uniform textures path must be to your .pbo
      };
};
              
