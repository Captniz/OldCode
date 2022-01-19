using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class WorkBenchScript : MonoBehaviour
{
    private List<string> collisions = new List<string>();

    public Transform spawner;
    // Start is called before the first frame update
    void Awake()
    {

        Debug.Log("Ficarra e Piccone"); 
    }


    public void OnCollisionEnter(Collision collision)
    {
        // aggiugne componente alla lista
        collisions.Add(collision.collider.GetComponent<Pickupable>().WhatAmI);
        collisions.Add(collision.collider.name);



        //se piccone
        if (collisions.Contains("LongStick") && collisions.Contains("PickaxeHead")){

            Debug.Log("Ficarra e Piccone"); 

            //Instantiate(GameObject.Find("PickAxe"), spawner.position, spawner.rotation);
                //TODO porcoddio se sto codice di merda non va (Usa ID + WhatAmI per capire rispettivamente l'oggetto specifico e il tipo) 
                if (collision.collider.GetComponent<Pickupable>().WhatAmI == "LongStick"){
                    Destroy(collision.collider.gameObject);   
                }

                if (collision.collider.GetComponent<Pickupable>().WhatAmI == "PickaxeHead"){
                    Destroy(collision.collider.gameObject);   
                }

/* 

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

 */
        }
    }

    public void OnCollisionExit(Collision collision)
    {
        collisions.Remove(collision.collider.GetComponent<Pickupable>().WhatAmI);
        collisions.Remove(collision.collider.name);
    }
}
    