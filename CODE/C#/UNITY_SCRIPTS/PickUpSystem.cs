using System.Net.Mime;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class PickUpSystem : MonoBehaviour
{
    GameObject CarriedObj;
    GameObject mainCamera;
    bool Carrying;
    public float Distance = 10f; 
    public float Smooth = 1f;
    public Text ComponentSignalingText;
    int i = 0;
    int l = 0;
    string ComponentTag = "";
    GameObject Spawnable;
    MeshRenderer CloneRenderer;
    MeshRenderer IngotRenderer;
    Material IngotMaterial;
    int ComponentIDs = 0;
    public bool NearAnvil;
    public bool NearSaw;
    public Transform GroundCheck;
    public float SphereRadius = 0.4f;
    public LayerMask NearAnvilMask;
    public LayerMask NearSawMask;

    void Awake()
    {
        mainCamera = GameObject.FindWithTag ("MainCamera");
    }

    void Carry(GameObject Item)
    {
        Item.transform.position = Vector3.Lerp (Item.transform.position, mainCamera.transform.position + mainCamera.transform.forward * Distance, Time.deltaTime * Smooth) ;
    }

    void Pickup()
    {
        if (Input.GetKeyDown(KeyCode.Mouse1))
        {
            int x = Screen.width / 2;
            int y = Screen.height / 2;

            Ray ray = mainCamera.GetComponent<Camera>().ScreenPointToRay(new Vector3(x,y));
            RaycastHit hit;


            if (Physics.Raycast(ray, out hit))
            {
                Pickupable p = hit.collider.GetComponent<Pickupable>();


                if (p != null)
                {
                    Carrying = true;
                    CarriedObj = p.gameObject;
                    p.gameObject.GetComponent<Rigidbody>().isKinematic = true;
                    p.gameObject.GetComponent<BoxCollider>().enabled = false;
                }
            }
        }
    }

    void DropCheck ()
    {
        if (Input.GetKeyDown(KeyCode.Mouse1))
        {
            DropObject();
        }
    }

    void DropObject ()
    {
        Carrying = false;
        CarriedObj.gameObject.GetComponent<Rigidbody>().isKinematic = false;
        CarriedObj.gameObject.GetComponent<BoxCollider>().enabled = true;
        CarriedObj = null;
    }

    void Use()
    {
        if (Input.GetKeyDown(KeyCode.Mouse0))
        {
            int x = Screen.width / 2;
            int y = Screen.height / 2;

            Ray ray = mainCamera.GetComponent<Camera>().ScreenPointToRay(new Vector3(x,y));
            RaycastHit hit;

            if (Physics.Raycast(ray, out hit))
            {

                if (hit.collider.tag == "Rame")
                {
                    var p = hit.collider.GetComponent<CopperProprieties>();

                    if (p.Malleable == true)
                    {
                        //Distrugge Lingotto
                        Destroy(p.gameObject);
                        //Set Spawnable al oggetto corrispondente a quello che si vuole creare coi tag
                        Spawnable = GameObject.FindGameObjectWithTag(ComponentTag); 
                        //Si crea il clone 
                        var Clone = Instantiate(Spawnable,p.transform.position,p.transform.rotation);  
                        //Si assegna al clone un numero per ritrovamento veloce
                        Clone.name = ComponentIDs.ToString();
                        //Dare il tag del materiale corrispondente al clone
                        Clone.tag = p.tag;
                        //Si definisce che cosa è il componente
                        Clone.GetComponent<Pickupable>().WhatAmI = ComponentTag;
                        //si trova il meshrenderer del oggetto creato
                        CloneRenderer = GameObject.Find(ComponentIDs.ToString()).GetComponent<MeshRenderer>();
                        //si trova il meshrenderer del lingotto
                        IngotRenderer = p.GetComponent<MeshRenderer>();
                        //si trova il meteriale del lingotto
                        IngotMaterial = IngotRenderer.material;
                        //si setta il materiale del clone uguale al lingotto
                        CloneRenderer.material = IngotMaterial;
                        //Aumento del ID per nomi facili da ritrovare
                        ComponentIDs += 1;
                    }
                }

                if (hit.collider.tag == "Aluminum")
                {
                    var p = hit.collider.GetComponent<AluminiumProprieties>();

                    if (p.Malleable == true)
                    {
                        //Distrugge Lingotto
                        Destroy(p.gameObject);
                        //Set Spawnable al oggetto corrispondente a quello che si vuole creare coi tag
                        Spawnable = GameObject.FindGameObjectWithTag(ComponentTag); 
                        //Si crea il clone 
                        var Clone = Instantiate(Spawnable,p.transform.position,p.transform.rotation);  
                        //Si assegna al clone un numero per ritrovamento veloce
                        Clone.name = ComponentIDs.ToString();
                        //Dare il tag del materiale corrispondente al clone
                        Clone.tag = p.tag;
                        //Si definisce che cosa è il componente
                        Clone.GetComponent<Pickupable>().WhatAmI = ComponentTag;
                        //si trova il meshrenderer del oggetto creato
                        CloneRenderer = GameObject.Find(ComponentIDs.ToString()).GetComponent<MeshRenderer>();
                        //si trova il meshrenderer del lingotto
                        IngotRenderer = p.GetComponent<MeshRenderer>();
                        //si trova il meteriale del lingotto
                        IngotMaterial = IngotRenderer.material;
                        //si setta il materiale del clone uguale al lingotto
                        CloneRenderer.material = IngotMaterial;
                        //Aumento del ID per nomi facili da ritrovare
                        ComponentIDs += 1;
                    }
                }

                if (hit.collider.tag == "Wood")
                {
                    var p = hit.collider.GetComponent<WoodProprieties>();

                    if (p.OnSaw == true)
                    {
                        //Distrugge Lingotto
                        Destroy(p.gameObject);
                        //Set Spawnable al oggetto corrispondente a quello che si vuole creare coi tag
                        Spawnable = GameObject.FindGameObjectWithTag(ComponentTag); 
                        //Si crea il clone 
                        var Clone = Instantiate(Spawnable,p.transform.position,p.transform.rotation);  
                        //Si assegna al clone un numero per ritrovamento veloce
                        Clone.name = ComponentIDs.ToString();
                        //Dare il tag del materiale corrispondente al clone
                        Clone.tag = p.tag;
                        //Si definisce che cosa è il componente
                        Clone.GetComponent<Pickupable>().WhatAmI = ComponentTag;
                        //si trova il meshrenderer del oggetto creato
                        CloneRenderer = GameObject.Find(ComponentIDs.ToString()).GetComponent<MeshRenderer>();
                        //si trova il meshrenderer del lingotto
                        IngotRenderer = p.GetComponent<MeshRenderer>();
                        //si trova il meteriale del lingotto
                        IngotMaterial = IngotRenderer.materials[1];
                        //si setta il materiale del clone uguale al lingotto
                        CloneRenderer.material = IngotMaterial;
                        //Aumento del ID per nomi facili da ritrovare
                        ComponentIDs += 1;
                    }
                }
            }
        }
    }

    void ChangeComponent() 
    {
        if (Input.GetKeyDown(KeyCode.Tab) && NearAnvil)
        {
            i += 1;

            if (i== 4)
            {
                i=0;
            }

            if (i==0)
            {
                ComponentSignalingText.text = "Picaxe";  
                ComponentTag = "PickaxeHead";
            }

            if (i==1)
            {
                ComponentSignalingText.text = "Axe";   
                ComponentTag = "AxeHead";
            }

            if (i==2)
            {
                ComponentSignalingText.text = "Sword";   
                ComponentTag = "SwordHead";
            }

            if (i==3)
            {
                ComponentSignalingText.text = "Sword Cover";  
                ComponentTag = "SwordGuard"; 
            }
        }

        if (Input.GetKeyDown(KeyCode.Tab) && NearSaw)
        {
            l += 1;

            if (l== 2)
            {
                l=0;
            }

            if (l==0)
            {
                ComponentSignalingText.text = "Long Stick";  
                ComponentTag = "LongStick";
            }

            if (l==1)
            {
                ComponentSignalingText.text = "Short Stick";   
                ComponentTag = "ShortStick";
            }
            
        }
    }
    void Update()
    {
        //check possibility of switching components
        NearAnvil = Physics.CheckSphere(GroundCheck.position,SphereRadius,NearAnvilMask);
        NearSaw = Physics.CheckSphere(GroundCheck.position,SphereRadius,NearSawMask);

        //check possibility of status of carried obj
        if (Carrying){
            Carry(CarriedObj);
            DropCheck();
        }else{
            Pickup();
        }

        ChangeComponent();

        Use();

        if (!NearAnvil && !NearSaw)
        {
            ComponentSignalingText.text = "";
        }
    }
}
