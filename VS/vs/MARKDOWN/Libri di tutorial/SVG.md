# SVG <!-- omit in toc -->

---

Guida al linguaggio SVG

---

## Indice <!-- omit in toc -->

- [Basi](#basi)
- [Tag e attributi più usati](#tag-e-attributi-più-usati)
  - [Attributi](#attributi)
  - [Tag](#tag)

---

## Basi

Il linguaggio SVG è quasi totalmente XML, per questo può essere implementato in un file HTML o può essere creato come file standalone. A un codice SVG può essere linkato un file CSS esternamente, ma solo se è all'interno di un file HTML; se il file è standalone il codice CSS deve essere per forza incluso in un tag style al interno del file.

<br>

**Basi del file SVG:**
Il file SVG si apre con un tag _svg_ (dato che questo linguaggio è estremamente simile a HTML per quanto riguarda la sintassi).

```svg
<svg width="720" height="1280" version="1.1" xmlns="http://www.w3.org/2000/svg">

<!--CODICE-->

</svg>
```

Dentro questo tag verrà insrito qualunque cosa (come il tag _html_ in HTML).

> **_width/height:_** Definiscono l'altezza e la larghezza dell' immagine, paragonabile alla risoluzione.  
> **_version:_** Definisce la versione di codice SVG che andremo ad usare.  
> **_xmlns:_** Definisce il namespace dell' XML.

<br>

Ora si potrebbe gia iniziare a scrivere del codice per creare delle forme, tuttavia non avrebbero colore o attributi particolari, per questo serve il tag style per inserire dei CSS.

```svg
<svg width="720" height="1280" version="1.1" xmlns="http://www.w3.org/2000/svg">
    <style>
        rect{
            fill: rgba(0,255,0,255);
        }
    </style>

<!--(fill -> Proprietà per dare colore alle figure)-->

    <rect width="720" height="1280" />
</svg>
```

Il tag _style_ funziona allo stesso modo che in HTML.

## Tag e attributi più usati

### Attributi

> **_width/height:_** Scala della forma.  
> **_x/y:_** Posizione della forma.  
> **_class:_** Classe di CSS.

### Tag

<br>

> **_rect:_**

```svg
<!--Rettangolo-->
<rect width="100" height="100" class="class"></rect>
```

---

<br>

> **_circle:_**

```svg
<!--Cerchio-->
<circle cx="10" cy="10" r="10" class="class"></circle>
```

> **_cx/cy:_** Definiscono la posizione del centro del crechio.  
> **_r:_** Definisce il raggio del crechio.

---

<br>
